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

int n , r;
int a[maxn] , cnt[maxn] , cnt2[maxn] , pt , ps[maxn] , f[maxn] , b[maxn];
vector<int> v;

int cal(int x){
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == r){
			b[i] = -1;
		} else if(a[i] == x){
			b[i] = 1;
		} else {
			b[i] = 0;
		}
	}
	memset(f , 63 , sizeof(f));
	int mn = 0;
	ps[0] = b[0];
	mn = min(0 , b[0]);
	for(int i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + b[i];
		mn = min(mn , ps[i]);
	}
	f[-mn] = -1;
	for(int i = 0 ; i < n ; i++){
		ps[i] -= mn;
		if(f[ps[i]] > n){
			f[ps[i]] = i;
		}
		res = max(res , i - f[ps[i]]);
	}
	return res;
}

void add(int i){
	pt += (pt == cnt[i]);
	cnt2[cnt[i]]--;
	cnt2[++cnt[i]]++;
	return;
}

void del(int i){
	cnt2[cnt[i]]--;
	cnt2[--cnt[i]]++;
	pt -= (cnt2[pt] == 0);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];;
		cnt[--a[i]]++;
	}
	int mx = -1;
	r = -1;
	for(int i = 0 ; i < n ; i++){
		if(cnt[i] > mx){
			mx = cnt[i];
			r = i;
		} else if(cnt[i] == mx){
			r = -1;
		}
	}
	if(r == -1){
		cout<<n<<'\n';
		return 0;
	}
	if(mx == n){
		cout<<"0\n";
		return 0;
	}
	int sq = min(n , 450) , ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(i == r) continue;
		if(cnt[i] >= sq){
			ans = max(ans , cal(i));
		}
	}
	v.push_back(-1);
	for(int i = 0 ; i < n ; i++){
		if(a[i] == r){
			v.push_back(i);
		}
	}
	v.push_back(n);
	int vs = mx + 2 , lm = min(sq , mx);
	for(int j = 1 ; j < lm ; j++){
		memset(cnt , 0 , sizeof(cnt));
		cnt2[0] = n; pt = 0;
		for(int i = 0 ; i < j ; i++){
			for(int k = v[i] + 1 ; k < v[i + 1] ; k++){
				add(a[k]);
			}
		}
		for(int i = j + 1 ; i < vs ; i++){
			for(int k = v[i - 1] + 1 ; k < v[i] ; k++){
				add(a[k]);
			}
			if(cnt2[j] > 0){
				ans = max(ans , v[i] - v[i - j - 1] - 1);
			}
			for(int k = v[i - j - 1] + 1 ; k < v[i - j] ; k++){
				del(a[k]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}