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

char a[1000111];
int f[1000111][2];
int n;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int j=0;j<2;j++){
		for (int x=0;x<2;x++)for (int y=0;y<2;y++) {
			if (j==0 && x > y)continue;
			if (j==0 && x < y && a[i] == '0')continue;
			f[i+1][j | (x < y)] = (f[i+1][j | (x < y)] + f[i][j]) % M;
		}
	}
	cout << f[n][1] << endl;
	return 0;
}