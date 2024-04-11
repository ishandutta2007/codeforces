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

pair<long long, pair<int, int> > q[1000111];
int a[111111],b[111111],A[111111],B[111111],n,ll[111111],rr[111111];
double l,r,c;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d%d",&q[i].S.F,&q[i].S.S), q[i].F = q[i].S.F + q[i].S.S;
	sort(q,q+n);
	l=0;
	r=5e9;
	a[0] = q[0].S.F - q[0].S.S;
	b[0] = q[0].S.F - q[0].S.S;
	A[n - 1] = q[n - 1].S.F - q[n - 1].S.S;
	B[n - 1] = q[n - 1].S.F - q[n - 1].S.S;

	for (int i = 1; i < n; i++) {
		a[i] = min(a[i - 1], q[i].S.F - q[i].S.S);
		b[i] = max(b[i - 1], q[i].S.F - q[i].S.S);
	}

	for (int i = n - 2; i >= 0; i--) {
		A[i] = min(A[i + 1], q[i].S.F - q[i].S.S);
		B[i] = max(B[i + 1], q[i].S.F - q[i].S.S);
	}

	for (int it=0;it<200;it++){
		c = (l + r) / 2;
		int ok = 0;
		ll[0] = 0;
		for (int i = 1; i < n; i++) {
			ll[i] = ll[i - 1];
			while (q[i].F - q[ll[i]].F > c + c) ll[i] ++;
		}
		for (int i = 0; i < n; i++) {
			long long MIN = 1e10;
			long long MAX = -1e10;
			if (ll[i] != 0) {
				MIN = a[ll[i] - 1];
				MAX = b[ll[i] - 1];
			}
			if (i != n - 1) {
				MIN = min(MIN, 1ll*A[i + 1]);
				MAX = max(MAX, 1ll*B[i + 1]);
			}
			if (MAX - MIN <= c + c) {
				ok = 1;
				break;
			}
		}
		if (ok) r = c; else l = c;
	}
	printf("%.10lf\n",l);
	return 0;
}