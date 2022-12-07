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

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
int a[N];


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	a[0] = 1;
	int g = k;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			a[i + 1] = a[i] + g;
		} else {
			a[i + 1] = a[i] - g;
		}
		g--;
	}
	for (int i = k + 1; i < n; i++) a[i] = i + 1;
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i == n- 1) puts(""); else putchar(' ');
	}
	return 0;
}