#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
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

#define MN 1000005
int n, a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;
    for(int i=0; a*i <= n; ++i){
        int o = n-a*i;
        if(o % b == 0){
            int j = o/b;
            //cout << "found " << i << " " << j << "\n";
            F0R(k, i){
                int l = k*a+1, r=(k+1)*a;
                //cout << l << " " << r << "\n";
                FOR(aah, l+1, r){
                    cout << aah << " ";
                }
                cout << l << " ";
            }
            F0R(k, j){
                int l=a*i+k*b+1, r=a*i+(k+1)*b;
                //cout << l << " " << r << "\n";
                FOR(aah, l+1, r){
                    cout << aah << " ";
                }
                cout << l << " ";
            }

            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}