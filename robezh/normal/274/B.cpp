#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int n;
vector<int> G[100005];
int val[100005];
int used[100005];

P dfs(int p){
	used[p] = true;
	ll mpos = 0, mneg = 0;
	for(int i = 0; i < G[p].size(); i++){
		if(!used[G[p][i]]){
			P pi = dfs(G[p][i]);
			mpos = max(mpos, pi.first);
			mneg = max(mneg, pi.second);
		}
	}
	if(mpos - mneg > val[p]) mneg = mpos - val[p];
	else mpos = mneg + val[p];
	P res = P(mpos, mneg);
	return res;
}

int main(){
	scanf("%d", &n);
	int a,b;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	fill(used+1, used+n+1, false);
	for(int i = 1; i <= n; i++){
		scanf("%d", &val[i]);
	}
	P res = dfs(1);
	cout << res.first + res.second;
	
}