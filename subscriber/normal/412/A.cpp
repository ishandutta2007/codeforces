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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, k;
char a[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d %d\n", &n, &k);
	k--;
	gets(a);
	if (k < n - 1 - k) {
		for (int i = 0; i < k; i++) puts("LEFT");
		for (int i = 0; i < n; i++) {
			printf("PRINT %c\n", a[i]);
			if (i < n - 1) puts("RIGHT");
		}
	} else {
		for (int i = k + 1; i < n; i++) puts("RIGHT");
		for (int i = n - 1; i >= 0; i--) {
			printf("PRINT %c\n", a[i]);
			if (i > 0) puts("LEFT");
			
		}
	}
	return 0;
}