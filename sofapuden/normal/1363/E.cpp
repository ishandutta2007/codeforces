#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef long long ll;
vector<vector<int>> gr;
vector<int> cost, cur, ned;

ll ans = 0;

void fil(int x, int p, int val){
	cost[x] = min(cost[x],val);
	for(auto y : gr[x]){
		if(y == p)continue;
		fil(y,x,cost[x]);
	}
}
pair<int,int> flp(int x, int p){
	pair<int,int> c = {0,0};
	if(cur[x] == 1 && ned[x] == 0)c.f = 1;
	if(cur[x] == 0 && ned[x] == 1)c.s = 1;
	for(auto y : gr[x]){
		if(y == p)continue;
		pair<int,int> no = flp(y,x);
		c.f+=no.f;
		c.s+=no.s;
	}
	ll cu = min(c.f,c.s);
	ans+=2*cu*cost[x];
	c.f-=cu;
	c.s-=cu;	
	return c;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	gr.resize(n);
	cost.resize(n);
	cur.resize(n);
	ned.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> cost[i] >> cur[i] >> ned[i];
	}
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	fil(0,0,cost[0]);
	pair<int,int> c = flp(0,0);
	if(c.first != 0 || c.second != 0){
		cout << "-1\n";
		return 0;
	}
	cout << ans << '\n';

}