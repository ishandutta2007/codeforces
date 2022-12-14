//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 4e6 + 9;
const ll Mod = 1e9 + 7;
ll gcd(ll a,ll b){ return (a < b)?gcd(b,a):(b?(gcd(b,a%b)):a); }
ll lcm(ll a,ll b){ return (a / gcd(a,b)) * b; }
ll pw(ll a,ll b){ return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1)) % Mod:1; }
ll inv(ll a){ return pw(a,Mod - 2); }
ll arr[Maxn];
ll st1[Maxn],ed1[Maxn],st2[Maxn],ed2[Maxn];
ll X[2],Y[2],h[2],out[2];
int main(){
	ll m;
	cin >> m;
	cin >> h[0] >> out[0];
	cin >> X[0] >> Y[0];
	cin >> h[1] >> out[1];
	cin >> X[1] >> Y[1];
	int t = 0;
	for(int j = 0; j <= 4 * m;j++){
		if(out[0] == h[0] && out[1] == h[1]){
			cout << t << endl;
			return 0;
		}
		int x = h[0],y = h[1];
		if(!ed1[x] && st1[x]) ed1[x] = t;
		if(!st1[x]) st1[x] = t;
		if(!ed2[y] && st2[y]) ed2[y] = t;
		if(!st2[y]) st2[y] = t;
		for(int i = 0; i < 2;i++)
			h[i] = (h[i] * X[i] + Y[i]) % m;
		if(t < 3) cerr << h[0] << ' ' << h[1] << endl;
		t++;
	}
	if(!ed1[out[0]] || !ed2[out[1]]){
		cout << -1 << endl;
		return 0;
	}
	ll c1 = ed1[out[0]] - st1[out[0]],c2 = ed2[out[1]] - st2[out[1]];
	cerr << c1 << ' ' << c2 << endl;
	ll g = gcd(c1,c2);
	ll s1 = st1[out[0]],s2 = st2[out[1]];
//	if(s1 == s2){
//		cout << s1 << endl;
//		return 0;
//	}
	for(int i = 0; i <= 4 * Maxn;i++){
		if(((s1 + c1 * i) - s2) >= 0 && ((s1 + c1 * i) - s2) % c2 == 0){
			cout << s1 + c1 * i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}