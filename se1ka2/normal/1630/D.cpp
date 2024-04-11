#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000;

int gcd(int n, int m){
	if(m == 0) return n;
	return gcd(m, n % m);
}

ll a[1000005];
ll d[1000005];
int c[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		ll s = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			s += abs(a[i]);
		}
		int g = 0;
		for(int i = 0; i < m; i++){
			int b;
			cin >> b;
			g = gcd(g, b);
		}
		for(int i = 0; i < g; i++){
			d[i] = INF;
			c[i] = 0;
		}
		for(int i = 0; i < n; i++){
			d[i % g] = min(d[i % g], abs(a[i]));
			if(a[i] < 0) c[i % g]++;
		}
		ll t[2]{0};
		for(int i = 0; i < g; i++){
			t[c[i] % 2] += d[i];
		}
		cout << s - min(t[0], t[1]) * 2 << endl;
	}
}