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
using namespace std;
typedef pair<int,int> pt;

char a[1000111];
int f[1000111][2][3];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	gets(a);
	int n = strlen(a);
	f[0][0][0] = 1;
	for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 3; k++) {
		for (int m = 0; m < 2; m++) {
			if (m == 1 && (a[i] == '0' || a[i] == '1' || a[i] == '2')) continue;
			if (m == 0 && a[i] == '*') continue;
			if (k == 1 && m == 1) continue;
			if (k == 2 && m == 0) continue;
			int kk = 0;
			if (a[i] == '0' && j == 1) continue;
			if (a[i] == '2' && j == 0) continue;
			if (a[i] == '0') kk = 1; else if (a[i] == '2') kk = 2;
			if (a[i] == '1') {
				if (j == 0) kk = 2; else kk = 1;
			}
			f[i + 1][m][kk] = (f[i + 1][m][kk] + f[i][j][k]) % M;
		}
	}
	int ans = 0;
	for (int j = 0; j < 2; j++) for (int k = 0; k < 3; k++) {
		if (k == 2) continue;
		ans = (ans + f[n][j][k]) % M;
	}
	cout << ans << endl;
	return 0;
}