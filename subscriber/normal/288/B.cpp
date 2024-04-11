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

int n,k;
long long ans,f[1111][1111],C[1111][1111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	for (int i=0;i<=1001;i++)for (int j=0;j<=i;j++)
	if (j==0||j==i)C[i][j]=1;else C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	cin >> n >> k;
	ans=1;
	ans=(ans*k)%M;
	for (int i=0;i<n-k;i++)ans=(ans*(n-k))%M;
	f[1][1]=1;
	for (int i=0;i<k;i++)for (int j=1;j<=i;j++){
		long long q=1;
		for (int l=1;l<=k-i;l++){
			q=q*j%M;
			f[i+l][l]=(f[i+l][l]+f[i][j]*C[k-i][l]%M*q%M)%M;
		}
	}
	long long aa=0;
	for (int i=1;i<=k;i++)aa=(aa+f[k][i])%M;
	ans=ans*aa%M;
	cout << ans<< endl;
	return 0;

}