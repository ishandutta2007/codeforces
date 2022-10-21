#include<cstdio>
#include<iostream>
#include<queue>
#include<limits>	
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

int n,m,k,p;
int num[1005][1005];
int rsum[1005],csum[1005];
ll rmax[1000050], cmax[1000050];
priority_queue<int> qa,qb;
int ca = 0, cb = 0;

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&num[i][j]);
			rsum[i] += num[i][j];
			csum[j] += num[i][j];
		}
	}
	for(int i = 0; i < n; i++) qa.push(rsum[i]);
	for(int i = 0; i < m; i++) qb.push(csum[i]);
	ll res = -numeric_limits<ll>::max();
	
	rmax[0] = 0; cmax[0] = 0;
	for(int i = 1; i <= k; i++){
		int s = qa.top();
		qa.pop();
		rmax[i] = rmax[i-1] + s;
		qa.push(s - p * m);
		
		int t = qb.top();
		qb.pop();
		cmax[i] = cmax[i-1] + t;
		qb.push(t - p * n);
	}
	
	for(int i = 0; i <= k; i++){
		res = max(res, rmax[i] + cmax[k-i] - 1LL * i * (k-i) * p);
	}

	cout << res;
	
	return 0;
}