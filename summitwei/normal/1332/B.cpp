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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int t;
int n;
int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
map<int, vi> x;
int an[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n;
        F0R(i, n){
            int a;
            cin >> a;
            F0R(j, 11){
                if(a % p[j] == 0){
                    x[j].pb(i);
                    break;
                }
            }
        }

        int ti=0;
        for(auto u : x){
            ++ti;
            for(auto v : u.s){
                an[v] = ti;
            }
        }
        cout << ti << "\n";
        F0R(i, n){
            cout << an[i] << " ";
        }
        cout << "\n";
        x.clear();
    }
    
    return 0;
}