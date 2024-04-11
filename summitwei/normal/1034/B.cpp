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
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
ll n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    if(n > m) swap(n, m);
    if(n == 1){
        if(m % 6 < 3) cout << (m/6)*6;
        else cout << (m/6)*6+2*(m%3) << "\n";
        return 0;
    }
    if(n == 2){
        if(m == 2) cout << "0\n";
        else if(m == 3) cout << "4\n";
        else if(m == 7) cout << "12\n";
        else cout << m*2 << "\n";
        return 0;
    }

    if(n % 2 == 0 || m % 2 == 0){
        cout << n*m << "\n";
    } else{
        cout << n*m-1 << "\n";
    }


    return 0;
}