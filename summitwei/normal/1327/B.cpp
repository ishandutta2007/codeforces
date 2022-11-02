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
bool ree[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        int sad = -1;
        cin >> n;
        FOR(i, 1, n){
            int k;
            cin >> k;
            int ok = -1;
            F0R(_, k){
                int x;
                cin >> x;
                if(!ree[x] && ok == -1){
                    ok = x;
                }
            }
            if(ok == -1){
                sad = i;
            } else{
                ree[ok] = true;
            }
        }
        if(sad == -1) cout << "OPTIMAL\n";
        else{
            int bruh = -1;
            FOR(i, 1, n) if(!ree[i]) bruh = i;
            cout << "IMPROVE\n" << sad << " " << bruh << "\n";
        }
        FOR(i, 1, n) ree[i] = false;
        //memset(ree, 0, sizeof ree);
    }

    return 0;
}