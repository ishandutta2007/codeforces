#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1000005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

string s, t;
struct Suffix{
    int index;
    int thisRank;
    int nextRank;
};
bool comp(Suffix suf1, Suffix suf2){
    if(suf1.thisRank != suf2.thisRank) return suf1.thisRank < suf2.thisRank;
    return suf1.nextRank < suf2.nextRank;
}

Suffix suffs[MAX_N];
int indices[MAX_N];
int sufArr[MAX_N];
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

int lcp[MAX_N];
int inv[MAX_N];
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

int tree[MAX_N*4];
void build(int node, int a, int b){
    if(a == b){
        tree[node] = lcp[a-1];
        return;
    }

    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}
/*void update(int node, int a, int b, int i, int j, int val){
    if(a > b || a > j || b < i) return;
    if(a == b){
        tree[node] = val;
        return;
    }

    update(node*2, a, (a+b)/2, i, j, val);
    update(node*2+1, 1+(a+b)/2, b, i, j, val);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}*/
int query(int node, int a, int b, int i, int j){
    if(i > j) swap(i, j);
    if(a > b || a > j || b < i) return INF;

    if(a >= i && b <= j) return tree[node];

    int q1 = query(node*2, a, (a+b)/2, i, j);
    int q2 = query(node*2+1, 1+(a+b)/2, b, i, j);

    return min(q1, q2);
}

int num0, num1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    int slen = s.length();
    int tlen = t.length();

    suffArr(t);
    getLCP(t);
    build(1, 1, tlen);

    /*F0R(i, tlen){
        cout << sufArr[i] << " " << lcp[i] << "\n";
    }*/

    F0R(i, slen){
        if(s[i] == '0') num0++;
        else num1++;
    }

    int ans = 0;

    FOR(i, 1, tlen-1){
        //this is the 0 length
        ll otherTot = tlen - (1LL*num0*i);
        if(otherTot <= 0) break;

        if(otherTot % num1 != 0) continue;
        int j = otherTot/num1;
        //cout << i << " " << j << " possible\n";

        int works = true;

        int curr = 0;
        int past0 = -1, past1 = -1;
        F0R(k, slen){
            if(s[k] == '0'){
                if(past0 == -1){
                    past0 = curr;
                } else{
                    int pastSuf = inv[past0];
                    int thisSuf = inv[curr];
                    if(pastSuf > thisSuf){
                        swap(pastSuf, thisSuf);
                    }
                    int lcp = query(1, 1, tlen, pastSuf+1, thisSuf);
                    if(lcp < i){
                        works = false;
                        break;
                    }
                }
                curr += i;
            } else{
                if(past1 == -1){
                    past1 = curr;
                } else{
                    int pastSuf = inv[past1];
                    int thisSuf = inv[curr];
                    if(pastSuf > thisSuf){
                        swap(pastSuf, thisSuf);
                    }
                    int lcp = query(1, 1, tlen, pastSuf+1, thisSuf);
                    if(lcp < j){
                        works = false;
                        break;
                    }
                }
                curr += j;
            }
        }
        //cout << past0 << " " << past1 << "\n";

        if(i == j && works){
            int past0Suf = inv[past0];
            int past1Suf = inv[past1];
            if(past0Suf > past1Suf){
                swap(past0Suf, past1Suf);
            }
            if(query(1, 1, tlen, past0Suf+1, past1Suf) >= i){
                works = false;
            }
        }

        if(works){
            ans++;
        }
    }

    cout << ans << "\n";

    /*F0R(i, 3*tlen){
        cout << tree[i] << " ";
    }*/
    
    return 0;
}