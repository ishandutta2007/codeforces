#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 2011;
const int MOD=1000000007;
int n,m;
string s;
int b[N][N];
int x[N][N];
int y[N][N];

int dx[N][N];
int dy[N][N];

int xx[N][N];
int yy[N][N];

int lx[N][N];
int ly[N][N];
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<m; j++) b[i][j]=(s[j]=='R');
	}
	if(n==1 && m==1) {printf("1"); return 0;}

	for(int i=0; i<n; i++) {
		int cnt=0;
		for(int j=m-1; j>=0; j--) {
			x[i][j]=m-1-cnt;
			if(b[i][j]) cnt++;
		}
	}
	for(int j=0; j<m; j++) {
		int cnt=0;
		for(int i=n-1; i>=0; i--) {
			y[i][j]=n-1-cnt;
			if(b[i][j]) cnt++;
		}
	}

	if(x[0][0]>0) lx[0][1]=1, dx[0][x[0][0]]=1;
	if(y[0][0]>0) ly[1][0]=1, dy[y[0][0]][0]=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!i && !j) continue;
			lx[i][j+1]=(lx[i][j+1]+lx[i][j]-dx[i][j])%MOD;
			ly[i+1][j]=(ly[i+1][j]+ly[i][j]-dy[i][j])%MOD;
	
			if(x[i][j]>j) {
				lx[i][j+1]=(lx[i][j+1]+ly[i][j])%MOD;
				dx[i][x[i][j]]=(dx[i][x[i][j]]+ly[i][j])%MOD;
			}
			if(y[i][j]>i) {
				ly[i+1][j]=(ly[i+1][j]+lx[i][j])%MOD;
				dy[y[i][j]][j]=(dy[y[i][j]][j]+lx[i][j])%MOD;
			}
		}
	}

/*	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ", lx[i][j]);
		}
		printf("\n");
	} printf("\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%d ", ly[i][j]);
		}
		printf("\n");
	}*/
	ll ans=lx[n-1][m-1]+ly[n-1][m-1];
	cout<<(ans%MOD+MOD)%MOD;
}