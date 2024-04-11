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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int g[3333333],x,f[22][1111][111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> x;
	g[0]=0;
	for (int i=1;i<pw(21);i++)g[i]=1+g[i&(i-1)];
	for (int n=1;;n++){
		int k=(n+1)/2;
		int t=n%2;
		m0(f);
		f[0][0][0]=1;
		for (int i=0;i<k;i++)for (int o=0;o<pw(k);o++)for (int j=0;j<=x;j++)if (f[i][o][j]){
			for (int h=0;h<pw(k);h++)if ((o&h)==0){
				int b=0;
				for (int u=1;u<k;u++)if ((h&pw(u-1))&&(h&pw(u)))b=1;
				if (b)continue;
				int d=j+g[h]*4;
				if (t){
					if (i==k-1)d=j+g[h]*2-((h&pw(k-1))>0);else d-=((h&pw(k-1))>0)*2;
				}
				if (d>x)continue;
				if (t==0&&(h&pw(k-1)))continue;
				if (t==0&&h)continue;
				f[i+1][h][d]=1;
			}
		}
		for (int o=0;o<pw(k);o++)if (f[k][o][x]){
			CC(n);
			return 0;
		}
	}
	return 0;
}