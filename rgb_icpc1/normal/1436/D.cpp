#include<bits/stdc++.h>

using namespace std;

#define M 200005

vector<long long> con[M];

long long max_val[M], cnt[M], sum[M];
long long a[M];

void dfs(long long u){
	long long mx = 0, ssum = 0, cc = 0, tmp;
	
	if(con[u].size() == 0){
		max_val[u] = a[u];
		sum[u] = 0;
		cnt[u] = 1;
		return;
	}
	
	for(long long v : con[u]) dfs(v);
	
	for(long long v : con[u]){
		mx = max(mx, max_val[v]);
	}
	
	for(long long v : con[u]){
		ssum += sum[v];
		ssum += (mx - max_val[v]) * cnt[v];
		cc += cnt[v];
	}
	
	if(a[u] < ssum){
		sum[u] = ssum - a[u];
		max_val[u] = mx;
		cnt[u] = cc;
	}
	else{
		tmp = a[u] - ssum;
		max_val[u] = mx + (tmp / cc) + (tmp % cc > 0);
		sum[u] = (tmp % cc) ? cc - tmp % cc : 0;
		cnt[u] = cc;
	}
}

int main(){
	
//	freopen("in.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long n, p, i;
	
	cin >> n;
	
	for(i = 2; i <= n; i ++){
		cin >> p;
		
		con[p].push_back(i);
	}
	
	for(i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	dfs(1);
	
	cout << max_val[1] << endl;
	
	return 0;
}