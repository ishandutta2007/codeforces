//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 4e5 + 9;
const int lg = 20;
const ll Mod = 1e9 + 7;
ll gcd(ll a,ll b){ return (a < b)?gcd(b,a):(b?(gcd(b,a%b)):a); }
ll lcm(ll a,ll b){ return (a / gcd(a,b)) * b; }
ll pw(ll a,ll b){ return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1)) % Mod:1; }
ll inv(ll a){ return pw(a,Mod - 2); }
ll arr[Maxn];
int sp[Maxn][lg];
pair<int,int> sr[Maxn];
int check(int p,int sz){
//	cerr << "Start\n";
	int x = arr[p];
	int cur = p;
	int cnt = 0;
	for(int i = lg - 1; i + 1;--i) if(sp[cur][i] >= x){
		cur += (1 << i);
		cnt += (1 << i);
	}
	cur = p;
	for(int i = lg - 1; i + 1;--i) if((cur - (1 << i) + 1) >= 0 && sp[cur - (1 << i) + 1][i] >= x){
		cur -= (1 << i);
		cnt += (1 << i);
	}
//	cout << x << ' ' << p << ' ' << cnt << ' ' << sz << endl;
	return ((cnt - 1) >= sz);
}
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i],sp[i][0] = arr[i],sr[i] = make_pair(arr[i],i);
	for(int i = 1; i < lg;i++){
		for(int j = 0; j < n - (1 << (i - 1));j++){
			sp[j][i] = min(sp[j][i-1],sp[j+(1 << (i - 1))][i-1]);
//			if(i <= 4){
//				cout << j << ' ' << i << ' ' << sp[j][i] << endl;
//			}
		}
	}
	sort(sr,sr+n);
	int ed = n-1;
	for(int sz = 1; sz <= n;sz++){
		while(ed && !check(sr[ed].second,sz)) ed--;
		cout << sr[ed].first << ' ';
	}
	
}