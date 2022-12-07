#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<cstring>
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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, m;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d\n", &n);
	char a[n][222222 / n];
	for (int i = 0; i < n; i++) {
		gets(a[i]);
	}
	m = strlen(a[0]);
	for (int i = 0; i < m; i++) {
		char g = 'z' + 1;
		int bad = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == '?') continue;
			if (a[j][i] == g) continue;
			if (g != ('z' + 1)) bad = 1;
			g = a[j][i];
		}
		if (g == ('z' + 1)) g--;
		if (bad)putchar('?'); else {
			putchar(g);
		}
	}
	puts("");
	return 0;
}