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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,m,ans,a[88][88];
int e[888][888],q[888][888],f[888],p[888],S,T,xx[888],yy[999],k,s, X[999],Y[999],ss;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)for (int j=0;j<m;j++) {
		cin >> a[i][j];
		a[i][j] --;
	}
	int k = (n*m / 2);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if ((i+j)%2==0) {
		xx[s] = i;
		yy[s++] = j;
	}else{
		X[ss] =i;
		Y[ss++] = j;
	}

	for (int i=0;i<k;i++) for (int j=0;j<k;j++) if (abs(xx[i]-X[j])+abs(yy[i]-Y[j]) == 1){
		int s =1;
		if (a[xx[i]][yy[i]] == a[X[j]][Y[j]]) s = 0;
		e[i][j+k] = s;
		e[j+k][i] = -s;
		q[i][j+k] = 1;
	}
	S = k + k;
	T = S +1;
	for (int i=0;i<k;i++) {
		q[S][i] = 1;
		q[i+k][T] = 1;
	}
	for (int it=0;it<k;it++){
		for (int i=0;i<=T;i++)f[i] = 1e9;
		f[S]=0;
		for(;;){
			int t=0;
			for (int i=0;i<=T;i++)for (int j=0;j<=T;j++)if (q[i][j] > 0 && f[i] + e[i][j] < f[j]) {
				t=1;
				f[j] = f[i] + e[i][j];
				p[j] = i;
			}
			if (!t)break;
		}
		ans += f[T];
		int x = T;
		while (x != S){
			q[p[x]][x] --;
			q[x][p[x]] ++;
			x = p[x];
		}
	}
	cout << ans << endl;
	return 0;
}