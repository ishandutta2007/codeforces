#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 3005
int t;
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> n >> m;
        F0R(i, n){
            F0R(j, m){
                if((n*m)%2 == 1){
                    if((i+j)%2 == 0) cout << 'B';
                    else cout << 'W';
                } else{
                    if(i == 0 && j == 0) cout << 'B';
                    else if((i+j)%2 == 1) cout << 'B';
                    else cout << 'W';
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}