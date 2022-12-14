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
deque<int> x,y;
int arr[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int turn = 0;
	int k1 = 0;
	int win = 0;
	int best = 0;
	cin >> k1;
	for(int i = 0; i < k1;i++){
		int p;
		cin >> p;
		x.push_back(p);
		if(p > best) best = p,win = 1;
	}
	int k2;
	cin >> k2;
	for(int i = 0; i < k2;i++){
		int p;
		cin >> p;
		y.push_back(p);
		if(p > best) best = p,win = 2;
	}
	while(x.size() && y.size()){
		if(turn == 1e7) break;
		int sz1 = x.size(),sz2 = y.size();
		if(x[0] > y[0]) x.push_back(y[0]),x.push_back(x[0]),x.pop_front(),y.pop_front();
		else y.push_back(x[0]),y.push_back(y[0]),y.pop_front(),x.pop_front();
		turn++;
	}
	if(turn == 1e7){
		cout << -1 << endl;
		return 0;
	}
	cout << turn << ' ' << win << endl;
}