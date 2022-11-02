#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

ll n,a,m,d,l; 
ll t[200000];

int main() {
	scanf( "%lld%lld%lld%lld", &n, &m, &a, &d ); 
	for (int i = 1; i <= m; ++i) scanf( "%lld", &t[i] ); 
	t[++m] = n * a; 
	sort(t+1, t+m+1); 
	l = (d / a + 1) * a; 
	ll p = -d; 
	ll ans = 0; 
	for (int i = 1; i <= m; ++i) {
		while (p + d < t[i]) {
			if ((p + d)/a+1 > n) {
				p = t[i]; 
				ans++; 
			}
			else {
				ll tmp = ((p+d)/a+1)*a; 
				if (tmp >= t[i]) {
					p = t[i]; 
					ans++; 
				}
				else {
					p = tmp; 
					ans++; 
					ll step; 
					if (n*a < tmp) step = (t[i]-tmp) / l; 
					step = min((t[i]-tmp)/l, (n*a-tmp)/l); 
					p = tmp + step * l; 
					ans += step; 
				}
			}
		}
	}
	cout<<ans<<endl; 
}