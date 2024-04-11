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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[2][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , sum = 0;
	cin>>n;
	for(ll t = 0 ; t < 2 ; t++){
		for(ll i = 0 ; i < n ; i++){
			ll h;
			cin>>h;
			a[t][i] += h;
			sum += h;
		}
	}
	for(ll t = 0 ; t < 2 ; t++){
		for(ll i = 0 ; i < n ; i++){
			ll h;
			cin>>h;
			a[t][i] -= h;
			sum -= h;
		}
	}
	if(sum != 0){
		cout<<"-1\n";
		return 0;
	}
	ll res = 0 , cnt[] = {0 , 0};
	for(ll i = 0 ; i < n ; i++){
		if(a[0][i] == 1 && a[1][i] == 1 && sum == -1){
			cnt[0]++;
			cnt[1]++;
			sum = 1;
			res++;
			continue;
		}
		if(a[0][i] == -1 && a[1][i] == -1 && sum == 1){
			cnt[0]--;
			cnt[1]--;
			sum = -1;
			res++;
			continue;
		}
		if(a[0][i] == 1){
			if(sum >= 0){
				cnt[0]++;
			} else {
				if(cnt[0] < 0){
					cnt[0]++;
				} else {
					cnt[1]++;
					res++;
				}
			}
			sum++;
		}
		if(a[0][i] == -1){
			if(sum <= 0){
				cnt[0]--;
			} else {
				if(cnt[0] > 0){
					cnt[0]--;
				} else {
					cnt[1]--;
					res++;
				}
			}
			sum--;
		}
		if(a[1][i] == 1){
			if(sum >= 0){
				cnt[1]++;
			} else {
				if(cnt[1] < 0){
					cnt[1]++;
				} else {
					cnt[0]++;
					res++;
				}
			}
			sum++;
		}
		if(a[1][i] == -1){
			if(sum <= 0){
				cnt[1]--;
			} else {
				if(cnt[1] > 0){
					cnt[1]--;
				} else {
					cnt[0]--;
					res++;
				}
			}
			sum--;
		}
		res += abs(sum);
	}
	cout<<res<<'\n';
	return 0;
}