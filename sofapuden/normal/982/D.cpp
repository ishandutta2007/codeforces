#include<bits/stdc++.h>

using namespace std;

map<int,int> M;
vector<int> v, p, s;

int u(int x) { return x ^ p[x] ? p[x] = u(p[x]) : x; } 

void add(int x, int val){
	M[x]+=val;
	if(!M[x])M.erase(x);
}

int main(){
	int n; cin >> n;
	v.resize(n);
	p.resize(n);
	s.resize(n,1);
	vector<pair<int,int>> v2;
	iota(p.begin(),p.end(),0);
	for(auto &x : v)cin >> x;
	for(int i = 0; i < n; ++i)v2.emplace_back(v[i],i);
	sort(v2.begin(),v2.end());
	int bes = 0, ans = 0;
	for(int i = 0; i < n; ++i){
		int ind = v2[i].second;
		add(1,1);
		if(ind && v[ind-1] < v[ind]){
			add(s[p[ind]],-1);
			p[ind] = u(ind-1);
			add(s[p[ind]],-1);
			s[p[ind]]++;
			add(s[p[ind]],1);
		}
		if(ind != n-1 && v[ind+1] < v[ind]){
			add(s[u(ind+1)],-1);
			add(s[u(ind)],-1);
			s[u(ind+1)]+=s[u(ind)], p[u(ind)] = p[u(ind+1)];
			add(s[u(ind)],1);
		}
		if(M.size() == 1 && M.begin()->second > bes){
			bes = M.begin()->second;
			ans = v2[i].first;
		}
	}
	cout << ans+1 << '\n';
}