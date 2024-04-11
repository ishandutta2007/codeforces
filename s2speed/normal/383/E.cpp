#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1.7e7 + 17 , md = 998244353 , inf = 2e16;

int ant[25] , bnt[25][25] , cnt[25][25][25];
int dp[maxn];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		int a = s[0] - 'a' , b = s[1] - 'a' , c = s[2] - 'a';
		if(a == b && b == c){
			ant[a]++;
			continue;
		}
		if(a == b) swap(b , c);
		if(a == c || b == c){
			ant[a]++; ant[b]++;
			bnt[a][b]++; bnt[b][a]++;
			continue;
		}
		ant[a]++; ant[b]++; ant[c]++;
		bnt[a][b]++; bnt[a][c]++; bnt[b][c]++; bnt[b][a]++; bnt[c][a]++; bnt[c][b]++;
		cnt[a][b][c]++; cnt[a][c][b]++; cnt[b][a][c]++; cnt[b][c][a]++; cnt[c][a][b]++; cnt[c][b][a]++;
	}
	int lm = (1 << 24) , res = 0;
	for(int mask = 1 ; mask < lm ; mask++){
		int st = -1 , nd = -1;
		for(int j = 0 ; j < 24 ; j++){
			if(mask & (1 << j)){
				if(st == -1){
					st = j;
				} else {
					nd = j;
					break;
				}
			}
		}
		if(nd == -1){
			dp[mask] = ant[st];
			continue;
		}
		int h = dp[mask ^ (1 << st)] + dp[mask ^ (1 << nd)] - dp[mask ^ (1 << st) ^ (1 << nd)] - bnt[st][nd];
		for(int j = 0 ; j < 24 ; j++){
			if(mask & (1 << j)){
				h += cnt[st][nd][j];
			}
		}
		dp[mask] = h;
	}
	for(int mask = 0 ; mask < lm ; mask++){
		res ^= dp[mask] * dp[mask];
	}
	cout<<res<<'\n';
	return 0;
}