#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
ll n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    for(ll i=2; i*i<=n; ++i){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            if(n != 1){
                cout << "1\n";
                return 0;
            } else{
                cout << i << "\n";
                return 0;
            }
        }
    }
    cout << n << "\n";

    return 0;
}