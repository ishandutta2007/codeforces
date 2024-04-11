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
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 311111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, t, a[N], d[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> t;
	for (int i = 0; i < n - 1; i++) scanf("%d", &a[i]);
	d[0] = 1;
	for (int i = 0; i < n - 1; i++) if (d[i]) d[i + a[i]] = 1;

	if (d[t - 1]) puts("YES"); else puts("NO");
	return 0;
}