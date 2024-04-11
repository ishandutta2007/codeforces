#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=1 << 20;
vector<array<int,3>>g[N];
vector<bool>used[N];
pair<int,int>v[N];
int ptr[N];

vector<int>res;

void eul(int x,int rofl=0){ 
	for(;ptr[x]<g[x].size();){
		if (used[x][ptr[x]]) {
			++ptr[x];
			continue;
		}
		int y=g[x][ptr[x]][0],rev=g[x][ptr[x]][1],kek=g[x][ptr[x]][2];
		used[y][rev]=true;
		++ptr[x];
		eul(y,kek);
	}
	res.push_back(rofl);
}


int pws[N];
int n;
bool check(int M, bool print) {
	int sz = 1 << M;
	for(int i=0;i<sz;++i)g[i].clear(), used[i].clear();
	fill(pws,pws+sz,0);
	int msk = sz - 1;
	for(int i=0;i<n;++i){
		int kek = v[i].first & msk;
		int mem = v[i].second & msk;
		++pws[kek];
		++pws[mem];
		g[kek].push_back({mem, (int)g[mem].size(), 2 * i+1});
		if (kek != mem)
			g[mem].push_back({kek, (int)g[kek].size() - 1, 2*i});
	}
	for(int i=0;i<sz;++i)
		used[i].resize(g[i].size());
	for(int i=0;i<sz;++i){
		if (pws[i]%2)
			return false;
	}
	fill(ptr,ptr+sz,0);
	res.clear();
	eul(v[0].first & msk);
	res.pop_back();
//	cerr << M << ' '<< res.size() << '\n';
	if (res.size() == n) { 
		if (!print)
			return true;
		cout << M << '\n';
		for(int x:res)
			cout << x + 1 << ' ' << (x ^ 1) + 1 << ' ';
		cout << '\n';
		return true;
	}
	else 
		return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> v[i].first >> v[i].second;
	int L = 0, R = 21;
	while(R - L > 1) {
		int M=(L+R)/2;
		if (check(M, false))
			L = M;
		else
			R = M;
	}
	check(L, true);
	return 0;
}