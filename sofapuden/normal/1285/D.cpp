#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int f(int l, int r, int b){
	if(b < 0)return 0;
	int ans = 0;
	int m = -1;
	for(int i = l; i <= r; ++i){
		if(!(v[i]&(1<<b))){
			m=i;
		}
	}
	if(m == -1 || m == r)return f(l,r,b-1);
	return (1<<b)|min(f(l,m,b-1),f(m+1,r,b-1));
}

int main(){
	int n; cin >> n;
	v.resize(n);
	for(auto &x : v)cin >> x;
	sort(v.begin(),v.end());
	cout << f(0,n-1,30) << '\n';
}