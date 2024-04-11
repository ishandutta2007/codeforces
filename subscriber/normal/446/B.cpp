#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, m, k, p;
int a[1111][1111];

vector<long long> solve(vector<int> a, long long v) {
	priority_queue<long long> Q;
	for (int i = 0; i < a.size(); i++) Q.push(a[i]);
	vector<long long> ret;
	long long sum = 0;
	ret.pb(0);
	for (int i = 0; i < k; i++) {
		long long x = Q.top();
		Q.pop();
		sum += x;
		ret.pb(sum);
		Q.push(x - v);
	}
	return ret;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m >> k >> p;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	
	vector<int> A, B;
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < m; j++) s += a[i][j];
		A.pb(s);
	}

	for (int i = 0; i < m; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) s += a[j][i];
		B.pb(s);
	}

	vector<long long> sA = solve(A, p * m);
	vector<long long> sB = solve(B, p * n);

/*	for (int i = 0; i < sA.size(); i++) cout << sA[i] << " ";
	cout << endl;
	for (int i = 0; i < sB.size(); i++) cout << sB[i] << " ";
	cout << endl;*/
	long long ans = -1e18;
	for (int i = 0; i <= k; i++) ans = max(ans, sA[i] + sB[k - i] - i * 1ll * (k - i) * p);
	cout << ans << endl;	

	return 0;
}