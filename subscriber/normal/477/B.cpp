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

int ans[N][4];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n, k;
	cin >> n >> k;
	int s = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			ans[i][j] = s;
			s++;
		}
		ans[i][3]++;
		s += 2;	
	}
	cout << ans[n - 1][3] * k<< endl;
	for (int i=  0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d", ans[i][j] * k);
			if (j == 3) puts(""); else putchar(' ');
		}
	}
	return 0;
}