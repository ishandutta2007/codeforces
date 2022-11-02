#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int t;
int n;

pair<pii, int> q[MN];
int res[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n){
            cin >> q[i].f.f >> q[i].f.s;
            q[i].s = i;
        }

        sort(q, q+n);
        
        int mx = q[0].f.s;

        int works = false;

        FOR(i, 1, n-1){
            if(mx < q[i].f.f){
                F0R(j, i){
                    res[q[j].s] = 1;
                }
                FOR(j, i, n-1){
                    res[q[j].s] = 2;
                }
                works = true;
                break;
            }

            mx = max(mx, q[i].f.s);
        }

        if(!works){
            cout << "-1\n";
        } else{
            F0R(i, n){
                cout << res[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}