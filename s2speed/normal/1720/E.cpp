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

const ll maxn = 512 , maxc = 25e4 + 17 , md = 1e9 + 7 , inf = 2e16;

int cnt[maxc] , li[maxc] , ri[maxc] , lj[maxc] , rj[maxc];
int a[maxn][maxn] , hnt[maxn][maxn];
vector<short int> v[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(li , 63 , sizeof(li));
	memset(ri , -1 , sizeof(ri));
	memset(lj , 63 , sizeof(lj));
	memset(rj , -1 , sizeof(rj));
	int n , k , cur = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>a[i][j]; a[i][j]--;
			cur += (++cnt[a[i][j]] == 1);
			li[a[i][j]] = min(li[a[i][j]] , i);
			ri[a[i][j]] = max(ri[a[i][j]] , i);
			lj[a[i][j]] = min(li[a[i][j]] , j);
			rj[a[i][j]] = max(rj[a[i][j]] , j);
		}
	}
	if(cur == k){
		cout<<"0\n";
		return 0;
	}
	if(cur < k){
		cout<<k - cur<<'\n';
		return 0;
	}
	int c = n * n;
	if(cur == c){
		ll h = c - k + 1 , sq = sqrt(h);
		if(sq * sq == h){
			cout<<"1\n";
		} else {
			cout<<"2\n";
		}
		return 0;
	}
	for(int k = 0 ; k < c ; k++){
		if(ri[k] == -1) continue;
		int i , j;
		i = li[k];
		for(j = 0 ; j <= lj[k] ; j++){
			int d = max(ri[k] - i , rj[k] - j);
			if(d + max(i , j) < n){
				v[i][j].push_back(d);
			}
		}
		j = lj[k];
		for(i = 0 ; i < li[k] ; i++){
			int d = max(ri[k] - i , rj[k] - j);
			if(d + max(i , j) < n){
				v[i][j].push_back(d);
			}
		}
	}
	int g = cur - k;
	for(int i = n - 1 ; ~i ; i--){
		for(int j = n - 1 ; ~j ; j--){
			for(auto d : v[i][j]){
				hnt[i + d][j + d]++;
			}
			int h = 0 , mx = max(i , j);
			for(int k = 0 ; k + mx < n ; k++){
				h += hnt[i + k][j + k];
				if(h == g || h == g + 1){
					cout<<"1\n";
					return 0;
				}
				if(h > g) break;
			}
		}
	}
	cout<<"2\n";
	return 0;
}