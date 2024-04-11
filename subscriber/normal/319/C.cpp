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
using namespace std;
typedef pair<int,int> pt;

int a[111111],b[111111],le[111111],ri[111111],e[111111],n,xx,q[111111];
vector<int> d[111111];
long long f[111111];
int top = -1, kk;
int i;

void gg(int x,int y) {
	int l = i;
	int r = n;
	while (l<r) {
		int c = (l+r) / 2;
		if (f[e[x]] + b[e[x]] * 1ll * a[c] < f[e[y]] + b[e[y]] * 1ll * a[c]) l = c + 1;else r = c;
	}
	d[l].pb(x);
	
}

void de(int x) {
	if (q[x])return;
	q[x] = 1;
	if (le[x] == -1) {
		xx = e[ri[x]];		
		le[ri[x]] = -1;
		return;
	}
	if (ri[x] == -1) {
		top = le[x];
		return;
	}
	le[ri[x]] = le[x];
	ri[le[x]] = ri[x];
	gg(le[x], ri[x]);
}

void add(int w) {
	kk ++;
	ri[top] = kk;
	le[kk] = top;
	ri[kk] = -1;
	e[kk] = w;
	if (top != -1) gg(top, kk);
	top = kk;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n ;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++)scanf("%d",&b[i]);
	a[n] = 1e9;
	f[0] = 0;
	xx = 0;
	add(0);
	for (i=1;i<n;i++){
		for (int j=0;j<d[i].size();j++)de(d[i][j]);
		f[i] = f[xx] + b[xx] * 1ll * a[i];
		add(i);
		for (int j=0;j<d[i].size();j++)de(d[i][j]);
	}
	cout << f[n-1] << endl;
	return 0;
}