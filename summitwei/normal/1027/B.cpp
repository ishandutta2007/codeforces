#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 505

int main(){
    ll n, q;
    cin >> n >> q;

    for(int i=0; i<q; i++){
        ll x, y;
        cin >> x >> y;

        ll ans = 0;

        if((x + y) % 2 == 0){
            ans += ((x-1)/2)*n;
            if(x % 2 == 0){
                ans += (n+1)/2;
            }
            
            ans += ((y-1)/2);
        } else{
            ans += (((n*n)+1)/2);

            //cout << "ans is " << ans << "\n";

            ans += ((x-1)/2)*n;
            //cout << "ans is " << ans << "\n";
            if(x % 2 == 0){
                ans += (n)/2;
                //cout << "ans is " << ans << "\n";
            }
            
            ans += ((y-1)/2);
        }
        cout << ans + 1 << "\n";
    }
    
    return 0;
}