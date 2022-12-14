//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 1e6 + 9;
const ll Mod = 1e9 + 7;
ll pw(ll a,ll b){ return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1))%Mod:1; }
ll gcd(ll a,ll b){ return (a < b)?gcd(b,a):(b?gcd(b,a%b):a); }
ll inv(ll a){ return pw(a,Mod-2); }
int arr[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	ll k,n,w;
	cin >> k >> n >> w;
	ll ban = k * ((w * (w + 1)) / 2);
	cout << max((ll)0,ban - n);
	return 0;
}