#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1005

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    F0R(i, t){
        ll a, b;
        cin >> a >> b;
        if(a-b != 1){
            cout << "NO\n";
            continue;
        }

        bool prime = true;
        FOR(j, 3, sqrt(a+b)+2){
            if((a+b)%j == 0 && a+b != j){
                prime = false;
                break;
            }
        }

        if(prime){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}