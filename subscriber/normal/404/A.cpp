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

int n;
char a[333][333];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) gets(a[i]);
	char c1 = a[0][0];
	char c2 = a[0][1];
	string ans = "YES";
	if (c1 == c2) ans = "NO";
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j || i == n - 1 - j) {
			if (a[i][j] != c1) ans = "NO";
		} else {
			if (a[i][j] != c2) ans = "NO";
		}
	}
	cout << ans << endl;
	return 0;
}