#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i < k; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;

int n, m;
double p[MAXN];
double a[MAXN][MAXN];
double f[MAXN][MAXN];
double tmp[MAXN][MAXN];

void read(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= m; i++)
		scanf("%lf", &p[i]);
}

void solve(){
	int o;
	for(o = 1; o <= m; o *= 2);
	for(int i = 0; i < o; i++)
		for(int j = 0; j < o; j++)
			a[i][i^j] += p[j];
	/*		
	rep(i,0,5){
		rep(j,0,5)
			cout<<a[i][j]<<' ';
			cout<<endl;
	}
*/	rep(i,0,o)rep(j,0,o)f[i][j] = a[i][j];
	n--;
//	rep(i,0,m+1)f[i][i] = 1;
	for(;n;n>>=1){
		if (n&1){
			rep(i,0,o)rep(j,0,o)tmp[i][j]=0;
			rep(k,0,o)rep(i,0,o)rep(j,0,o)tmp[i][j]+=f[i][k]*a[k][j];
			rep(i,0,o)rep(j,0,o)f[i][j]=tmp[i][j];
		}
		rep(i,0,o)rep(j,0,o)tmp[i][j]=0;
		rep(k,0,o)rep(i,0,o)rep(j,0,o)tmp[i][j]+=a[i][k]*a[k][j];
		rep(i,0,o)rep(j,0,o)a[i][j]=tmp[i][j];
	}	
	double ans =0;
/*	rep(i,0,5){
		rep(j,0,5)
			cout<<f[i][j]<<' ';
			cout<<endl;
	}*/
	printf("%.16lf\n", 1 - f[0][0]);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}