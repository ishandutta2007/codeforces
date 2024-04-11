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

int ff[666],C[666][666],f[666][666],n,a,b,x;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	for (int i=0;i<=555;i++)for (int j=0;j<=i;j++)if (j==0||i==j)C[i][j]=1;else C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	ff[0]=1;
	for (int i=1;i<=555;i++)ff[i] = (ff[i-1] * 1ll * i)%M;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x ;
		if (x==1)a++;else b++;
	}
	f[0][0]=1;
	for (int i=0;i<=a;i++)for (int j=0;j<=b;j++)if (f[i][j]){
		for (int k=1;k+j<=b;k++){
				f[i][j+k] = (f[i][j+k] + f[i][j] * 1ll * C[b-j-1][k-1] % M * ff[k-1])%M;
				if (i < a) {
					f[i+1][j+k] = (f[i+1][j+k] + f[i][j] * 1ll * C[b-j-1][k-1] % M * C[a-i][1] % M * ff[k])%M;
				}
				if (i + 1 < a) {
					f[i+2][j+k] = (f[i+2][j+k] + f[i][j] * 1ll * C[b-j-1][k-1] % M * C[a-i][2] % M * ff[k+1])%M;
				}
		}
		if (j == b) {
			if (i < a) {
				f[i+1][j] = (f[i+1][j] + f[i][j] * 1ll * C[a-i-1][0])%M;
			}
			if (i + 1 < a) {
				f[i+2][j] = (f[i+2][j] + f[i][j] * 1ll * C[a-i-1][1])%M;
			}
		}
	}
	cout << f[a][b] << endl;
	return 0;
}