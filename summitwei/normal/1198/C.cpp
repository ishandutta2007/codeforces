#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 500005
int t;
int n, m;
pii e[MN];
bool edu[MN];
bool veu[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        int cnt = 0;
        F0R(i, m){
            cin >> e[i].f >> e[i].s;
            if(veu[e[i].f] || veu[e[i].s]) continue;
            veu[e[i].f] = true;
            veu[e[i].s] = true;
            edu[i] = true;
            cnt++;
            //cout << e[i].f << " " << e[i].s << " good\n";
        }
        if(cnt >= n){
            cout << "Matching\n";
            cnt = 0;
            F0R(i, m){
                if(edu[i]){
                    cout << i+1 << " ";
                    cnt++;
                }
                if(cnt == n) break;
            }
            cout << "\n";
        } else{
            cout << "IndSet\n";
            cnt = 0;
            FOR(i, 1, 3*n){
                if(!veu[i]){
                    cout << i << " ";
                    cnt++;
                    if(cnt == n) break;
                }
            }
            cout << "\n";
        }
        FOR(i, 1, 3*n) veu[i] = false;
        F0R(i, m){
            e[i] = {0,0};
            edu[i] = false;
        }
    }

    return 0;
}