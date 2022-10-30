#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n, q;
string s;
struct Suffix{
    int index;
    int thisRank;
    int nextRank;
};
bool comp(Suffix suf1, Suffix suf2){
    if(suf1.thisRank != suf2.thisRank) return suf1.thisRank < suf2.thisRank;
    return suf1.nextRank < suf2.nextRank;
}
Suffix suffs[MN];
int indices[MN];
int sufArr[MN];
void suffArr(string str){
    int strLen = str.length();
    for(int i=0; i<strLen; i++){
        suffs[i].index = i;
        suffs[i].thisRank = str[i]-'a';
        if(i == strLen-1){
            suffs[i].nextRank = -1;
        } else{
            suffs[i].nextRank = str[i+1]-'a';
        }
    }
 
    sort(suffs, suffs+strLen, comp);
 
    for(int amt = 4; amt < 2*strLen; amt *= 2){
        int currRank = 0;
        
        int prevRank = suffs[0].thisRank;
        suffs[0].thisRank = 0;
        indices[suffs[0].index] = 0;
 
        for(int i=1; i<strLen; i++){
            if(suffs[i].thisRank != prevRank || suffs[i].nextRank != suffs[i-1].nextRank){
                currRank++;
            }
            prevRank = suffs[i].thisRank;
            suffs[i].thisRank = currRank;
            indices[suffs[i].index] = i;
        }
 
        for(int i=0; i<strLen; i++){
            int otherInd = suffs[i].index + amt/2;
            if(otherInd >= strLen){
                suffs[i].nextRank = -1;
            } else{
                suffs[i].nextRank = suffs[indices[otherInd]].thisRank;
            }
        }
 
        sort(suffs, suffs+strLen, comp);
    }
 
    for(int i=0; i<strLen; i++){
        sufArr[i] = suffs[i].index;
    }
}
int lcp[MN];
int inv[MN];
void getLCP(string str){
    int strLen = str.length();
    F0R(i, strLen){
        inv[sufArr[i]] = i;
    }
 
    int k = 0;
 
    F0R(i, strLen){
        if(inv[i] == strLen-1){
            k=0;
            continue;
        }
        int j = sufArr[inv[i]+1];
 
        while(i+k<strLen && j+k<strLen && str[i+k] == str[j+k]) k++;
 
        lcp[inv[i]] = k;
 
        if(k > 0) k--;
    }
}

int tree[MN*4];
void build(int node, int a, int b){
    if(a == b){
        tree[node] = lcp[a-1];
        return;
    }
 
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
 
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
int query(int node, int a, int b, int i, int j){
    if(i > j) swap(i, j);
    if(a > b || a > j || b < i) return INF;
 
    if(a >= i && b <= j) return tree[node];
 
    int q1 = query(node*2, a, (a+b)/2, i, j);
    int q2 = query(node*2+1, 1+(a+b)/2, b, i, j);
 
    return min(q1, q2);
}

vi a, b;
map<int, ll> aah;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    cin >> s;

    suffArr(s);
    getLCP(s);
    build(1, 1, n);
    
    /*F0R(i, n){
        cout << lcp[i] << " ";
    }
    cout << "\n";*/

    F0R(_, q){
        int k, l;
        cin >> k >> l;
        F0R(_, k){
            int x;
            cin >> x;
            a.pb(inv[x-1]);
            //cout << inv[x-1] << " ";
        }
        //cout << "\n";
        F0R(_, l){
            int x;
            cin >> x;
            b.pb(inv[x-1]);
            //cout << inv[x-1] << " ";
        }
        //cout << "\n";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll sm = 0;

        ll cur = 0;
        int j = l-1;
        RFOR(i, k-1, 0){
            //cout << "doing " << i << "\n";
            if(i != k-1){
                int val = query(1, 1, n, a[i]+1, a[i+1]);
                
                auto it = aah.upper_bound(val);
                for(; it!=aah.end(); ){
                    cur = cur+val*(it->s)-(it->f)*(it->s);
                    //cout << "incremented cur, now " << cur << "\n";
                    aah[val] += it->s;
                    it = aah.erase(it);
                }
            }
            while(j >= 0 && b[j] > a[i]){
                //cout << "hmm\n";
                int val = query(1, 1, n, a[i]+1, b[j]);
                
                cur += val;
                aah[val] += 1;

                --j;
            }
            if(j >= 0 && b[j] == a[i]){
                int loc = sufArr[a[i]];
                int ch = n-loc;
                sm += ch;
                //cout << "adding " << ch << "\n";
            }
            sm += cur;
        }
        aah.clear();
        j = k-1;
        //cout << sm << "\n";
        cur = 0;
        RFOR(i, l-1, 0){
            if(i != l-1){
                int val = query(1, 1, n, b[i]+1, b[i+1]);
                
                auto it = aah.upper_bound(val);
                for(; it!=aah.end(); ){
                    cur = cur+val*(it->s)-(it->f)*(it->s);
                    //cout << "incremented cur, now " << cur << "\n";
                    aah[val] += it->s;
                    it = aah.erase(it);
                }
            }
            while(j >= 0 && a[j] > b[i]){
                int val = query(1, 1, n, b[i]+1, a[j]);

                //cout << "adding " << val << "\n";
                
                cur += val;
                aah[val] += 1;

                --j;
            }
            sm += cur;
        }

        cout << sm << "\n";

        aah.clear();
        a.clear();
        b.clear();
    }

    return 0;
}