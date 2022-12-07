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
#define N 3111111
using namespace std;
typedef pair<int,int> pt;

int f[N];
int n, k;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	for (int i = 2; i < N; i++) if (!f[i]) 
		for (int j = i + i; j < N; j += i) f[j] = 1;
	cin >> n >> k;
	if (n == 1) {
		if (k != 0) {
			puts("-1");
		} else puts("1");
		return 0;
	}
	if (n / 2 > k) {
		puts("-1");
		return 0;
	}
	vector<int> a;
	int m = n / 2;
	int x = k - (m - 1);
	int x1 = x;
	int x2 = x * 2;
	a.pb(x1);
	a.pb(x2);
	int t = 5;
	for (int i = 0; i < n - 2; i++) {
		while (f[t] || x1 == t || x2 == t) t++;
		a.pb(t);
		t++;
	}
	for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
	cout << a[a.size() - 1] << endl;
	return 0;
}