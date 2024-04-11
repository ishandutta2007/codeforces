#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int n, d;
int x[100010];
ll ans;

ll f(ll p){ return p * (p - 1) / 2;}

int main(){
    cin >> n >> d;
    rep(i, n) cin >> x[i];
    rep(i, n){
	int m = upper_bound(x, x + n, x[i] + d) - x - 1;
	if(m - i < 2) continue;
	ans += f(m - i);
    }
    cout << ans << endl;
    return 0;
}