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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

void er(char s) {
	if (s == 's') puts("Stannis"); else puts("Daenerys");
	exit(0);
}


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	int n, k;
	cin >> n >> k;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x % 2 == 0) b++; else a++;
	}
	if (n == k) {
		if (a % 2) er('s'); else er('d');
	}
	int mv = n - k;
	if (mv / 2 >= a) er('d');
	if (mv / 2 >= b && k % 2 == 0) er('d');
	if ((mv + 1) / 2 >= b && k % 2 == 1) er('s');

	if (mv % 2 == 1) er('s'); else er('d');
			

	return 0;
}