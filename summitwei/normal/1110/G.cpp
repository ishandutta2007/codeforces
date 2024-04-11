#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1500005
int t;
int n;
vi e[MN];
int deg[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    F0R(_, t){
        int n;
        cin >> n;
        F0R(i, n-1){
            int u, v;
            cin >> u >> v;

            e[u].pb(v);
            e[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        string s;
        cin >> s;
        int on = n;
        FOR(i, 1, on){
            if(s[i-1] == 'W'){
                e[i].pb(n+1);
                e[n+1].pb(i);
                e[n+1].pb(n+2);
                e[n+2].pb(n+1);
                e[n+1].pb(n+3);
                e[n+3].pb(n+1);
                deg[i]+=1;
                deg[n+1]+=3;
                deg[n+2]++;
                deg[n+3]++;
                n+=3;
            }
        }

        int res = false;
        int ends = 0;
        int n3 = 0;
        FOR(i, 1, n){
            if(deg[i] >= 4){
                res = true;
                break;
            } else if(deg[i] == 3){
                //cout << i << " has deg 3\n";
                int cnt = 0;
                n3++;
                F0R(j, 3){
                    if(deg[e[i][j]] != 1) cnt++;
                }
                if(cnt >= 2){
                    res = true;
                    break;
                } else if(cnt == 1){
                    ends++;
                }
            }
        }
        //cout << "ends is " << ends << "\n";
        if(n3 == 2 && ends == 2 && n%2==1){
            res = true;
        }

        if(res){
            cout << "White\n";
        } else{
            cout << "Draw\n";
        }

        FOR(i, 1, n){
            deg[i] = 0;
            e[i].clear();
        }
    }

    return 0;
}