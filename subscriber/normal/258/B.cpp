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

string e;
int m;
long long f[55][9][555],u[55],ans;

long long pv(long long a,long long b){
	if (b==0)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

long long C(int n,int k){
	long long r=1;
	for (int i=0;i<k;i++)r=r*(n-i)%M;
	for (int i=1;i<=k;i++)r=r*pv(i,M-2)%M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> m;
	SS q;
	q<<m;
	e=q.str();
	f[0][0][0]=1;
	for (int i=0;i<e.size();i++)for (int j=0;j<2;j++)for (int s=0;s<=i;s++){
		for (int g='0';g<='9';g++){
			if (j==0&&g>e[i])continue;
			int jj=j;
			if (g<e[i])jj=1;
			int ss=s;
			if (g=='4'||g=='7')ss++;
			f[i+1][jj][ss]=(f[i+1][jj][ss]+f[i][j][s])%M;
		}
	}
	for (int j=0;j<2;j++)for (int s=0;s<=e.size();s++)u[s]=(u[s]+f[e.size()][j][s])%M;
	u[0]=(u[0]-1+M)%M;
	for (int d=0;d<51;d++)if (u[d]){
		u[d]--;
		m0(f);
		f[0][0][0]=120*6;
		for (int i=0;i<51;i++)for (int j=0;j<7;j++)for (int s=0;s<d;s++){
			for (int k=0;j+k<7&&k<=u[i];k++){
				long long ee=f[i][j][s];
				ee=ee*C(u[i],k)%M;
				f[i+1][j+k][s+k*i]=(f[i+1][j+k][s+k*i]+ee)%M;
			}
		}
		u[d]++;
		for (int s=0;s<d;s++)ans=(ans+f[51][6][s]*1ll*u[d])%M;
	}
	CC(ans);

	return 0;
}