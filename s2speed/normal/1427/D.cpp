#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 52;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll p[MAX_N] , d[MAX_N] , a[MAX_N];
vector<ll> q[4];
vector< vector<ll> > ans;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , x;
	vector<ll> v;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		p[a[i]] = i;
	}
	d[n - 1] = 1;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(p[i] == p[i + 1] - 1){
			d[i] = d[i + 1] + 1;
		} else{
			d[i] = 1;
		}
	}
	while(d[0] < n){
//		cout<<d[0]<<"\n";
		q[0].clear();
		q[1].clear();
		q[2].clear();
		q[3].clear();
		v.clear();
		for(int i = 0 ; i < n - 1 ; i++){
			if(d[i] == 1 && p[i + 1] < p[i]){
				x = i;
				break;
			}
		}
//		cout<<x<<"\n";
		v.push_back(0);
		ll l = p[x + 1] , y = -1;
		if(l > 0){
			v.push_back(l);
		}
		y += l;
		l = d[x + 1];
		v.push_back(l);
		y += l;
		l = p[x] - y;
		v.push_back(l);
		y += l;
		l = n - p[x] - 1;
		if(l > 0){
			v.push_back(l);
		}
		v[0] = v.size() - 1;
		ans.push_back(v);
		ll vs = v.size();
		y = 0;
		for(int i = 1 ; i < vs ; i++){
			for(int j = 0 ; j < v[i] ; j++){
				q[i - 1].push_back(a[y]);
				y++;
			}
		}
		y = 0;
		for(int i = 3 ; i >= 0 ; i--){
			ll qs = q[i].size();
			for(int j = 0 ; j < qs ; j++){
				a[y] = q[i][j];
				p[q[i][j]] = y;
				y++;
			}
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			if(p[i] == p[i + 1] - 1){
				d[i] = d[i + 1] + 1;
			} else{
				d[i] = 1;
			}
		}
/*		for(int i = 0 ; i < n ; i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";*/
	}
	ll as = ans.size();
	cout<<as<<"\n";
	for(int i = 0 ; i < as ; i++){
		ll o = ans[i].size();
		for(int j = 0 ; j < o ; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}