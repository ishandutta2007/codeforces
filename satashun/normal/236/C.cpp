#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll ans;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }

ll lcm_tri(int a, int b, int c){ return lcm(lcm((ll)a, (ll)b), (ll)c);}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = max(n - 100, 1); i <= n; i++){
	for(int j = i; j <= n; j++){
	    for(int k = j; k <= n; k++){
		ans = max(ans, lcm_tri(i, j, k));
	    }
	}
    }
    cout << ans << endl;
    return 0;
}