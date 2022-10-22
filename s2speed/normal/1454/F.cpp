#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int , int> pii;

const int MAX_N = 4e5 + 20;
 
set<ll> s;
vector<ll> v;
int a[MAX_N] , l[MAX_N] , ans = -1 , n , p[20] , x;
pii rm[2 * MAX_N][20];

void lp_build(){
	ll h = 1;
	l[0] = -1;
	for(int i = 1 ; i < MAX_N ; i++){
		l[i] = l[i - 1] + (i == h);
		if(h == i){
			h *= 2;
		}
	}
	h = 1;
	for(int i = 0 ; i < 20 ; i++ , h *= 2){
		p[i] = h;
	}
}

void RMQ_build(){
	for(int i = 0 ; i < 2 * n ; i++){
		for(int j = 0 ; j < 20 ; j++){
			rm[i][j] = {1e9 , -1};
		}
	}
	for(int i = 0 ; i < n ; i++){
		rm[i][0] = {a[i] , a[i]};
	}
	for(int j = 1 ; j < 20 ; j++){
		for(int i = 0 ; i < n ; i++){
			pii h;
			h.first = min(rm[i][j - 1].first , rm[i + p[j - 1]][j - 1].first);
			h.second = max(rm[i][j - 1].second , rm[i + p[j - 1]][j - 1].second);
			rm[i][j] = h;
		}
	}
}

int bs(int k){
	int l = 0 , r = v.size();
	while(l < r - 1){
		int m = (l + r) / 2;
		if(v[m] == k){
			return m;
		}
		if(v[m] > k){
			r = m;
		} else {
			l = m + 1;
		}
	}
	return l;
}
 
int ch(int x , int k , int o){
	int a , b;
	a = min(rm[k][l[o - k]].first , rm[o - p[l[o - k]]][l[o - k]].first);
	b = max(rm[o][l[n - o]].second , rm[n - p[l[n - o]]][l[n - o]].second);
//	cout<<k<<" "<<o<<" "<<l[o - k]<<" "<<l[n - o]<<" "<<p[l[o - k]]<<" "<<p[l[n - o]]<<" "<<a<<" "<<b<<" "<<rm[k][l[o - k]].first<<" "<<rm[o - p[l[o - k]]][l[o - k]].first<<"\n";
	if(a < x && b > x){
		return -1;
	}
	if(a < x || b < x){
		return 0;
	}
	if(b > x || a > x){
		return 1;
	}
	return 2;
}
 
void s2(int k){
	k++;
	int l = k , r = n;
	while(l < r && l < n - 1 && r > k){
//		cout<<l<<" "<<r<<"\n";
		int m = (l + r - 1) / 2 , o = ch(x , k , m + 1);
		if(o == -1){
			return;
		}
		if(o == 0){
			r = m;
		}
		if(o == 1){
			l = m + 1;
		}
		if(o == 2){
			ans = m;
			return;
		}
	}
}
 
void solve(){
	x = -1;
	ans = -1;
	s.clear();
	v.clear();
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		if(!s.count(a[i])){
			s.insert(a[i]);
			v.push_back(a[i]);
		}
	}
	sort(v.begin() , v.end());
	for(int i = 0 ; i < n ; i++){
		a[i] = bs(a[i]);
	}
	RMQ_build();
	for(int i = 0 ; i < n ; i++){
		x = max(x , a[i]);
		s2(i);
		if(ans != -1){
			cout<<"YES\n";
			cout<<i + 1<<" "<<ans - i<<" "<<n - ans - 1<<"\n";
			return;
		}
	}
	cout<<"NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	lp_build();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}