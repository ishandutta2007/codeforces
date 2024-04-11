#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n; string s;
int q;
int k[MN]; string m[MN]; vi mat[MN];

const int K=26;
struct Vertex{
    int nxt[K];
    int leaf = 0;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int exit = -1;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(nxt), end(nxt), -1);
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t(1);

void add(string const& s, int x){
    int v = 0;
    for(char ch : s){
        int c = ch-'a';
        if(t[v].nxt[c] == -1){
            t[v].nxt[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].nxt[c];
    }
    t[v].leaf = x;
}

int go(int v, char ch);
int gl(int v){
    if(t[v].link == -1){
        if(v == 0 || t[v].p == 0){
            t[v].link = 0;
        } else{
            t[v].link = go(gl(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}
int go(int v, char ch){
    int c = ch-'a';
    if(t[v].go[c] == -1){
        if(t[v].nxt[c] != -1){
            t[v].go[c] = t[v].nxt[c];
        } else{
            t[v].go[c] = v==0 ? 0 : go(gl(v), ch);
        }
    }
    return t[v].go[c];
}

int gex(int v){
    //cout << "doing " << v << "\n";
    if(t[v].exit == -1){
        if(v == 0 || t[v].link == 0){
            t[v].exit = 0;
        } else{
            int up = gl(v);
            if(t[up].leaf){
                t[v].exit = up;
            } else{
                t[v].exit = gex(up);
            }
        }
    }
    return t[v].exit;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s; n = s.length();
    cin >> q;
    FOR(i, 1, q){
        cin >> k[i] >> m[i];
        add(m[i], i);
    }

    int v = 0;
    F0R(i, n){
        //cout << "proc " << i << "\n";
        int ch = s[i]-'a';
        while(v != 0 && t[v].nxt[ch] == -1){
            v = gl(v);
        }
        v = t[v].nxt[ch];
        if(v == -1) v = 0;

        int ot = v;
        while(ot != 0){
            if(t[ot].leaf){
                mat[t[ot].leaf].pb(i);
                //cout << "match found at " << i << " " << ot << " " << t[ot].leaf << "\n";
            }
            ot = gex(ot);
        }
    }

    FOR(i, 1, q){
        if(mat[i].size() < k[i]){
            cout << "-1\n";
            continue;
        }
        /*cout << "apps for " << i << ":\n";
        for(auto u : mat[i]) cout << u << " ";
        cout << "\n";*/
        int ans = INF;
        FOR(j, k[i]-1, mat[i].size()-1){
            ans = min(ans, mat[i][j]-mat[i][j-k[i]+1]);
        }
        //cout << ans << "\n";
        cout << ans+m[i].size() << "\n";
    }

    return 0;
}