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
#define MM 1000000006
#define N 211111
using namespace std;
typedef pair<int,int> pt;

char s[N], a[N];
vector<char> v[N];

long long len[10], val[10];
int n;

long long pv(long long a, long long b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	gets(s);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(a);
		int k = strlen(a);
		for (int j = 0; j < k; j++) v[i].pb(a[j]);
	}		
	for (int i = 0; i < 10; i++) {
		len[i] = 1;
		val[i] = i % M;
	}
	for (int i = n - 1; i >= 0; i--) {
		int x = v[i][0] - '0';
		long long va = 0;
		long long le = 0;

		for (int j = v[i].size() - 1; j >= 3; j--) {
			va = (va + val[v[i][j] - '0'] * 1ll * pv(10, le)) % M;
			
			le = (le + len[v[i][j] - '0']) % MM;
		}
		val[x] = va;
		len[x] = le;
	}
	long long p = 0;
	long long ans = 0;

	int k = strlen(s);	
	for (int i = k - 1; i >= 0; i--) {
		int x = s[i] - '0';
		ans = (ans + val[x] * 1ll * pv(10, p)) % M;
		p = (p + len[x]) % MM;
	}
	cout << ans << endl;

	return 0;
}