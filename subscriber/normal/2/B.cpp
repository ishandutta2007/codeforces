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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,a[1111][1111],a1[1111][1111],a2[1111][1111],f1[1111][1111],f2[1111][1111],p1[1111][1111],p2[1111][1111],x=-1,y,xx,yy,as1,bs1,as2,bs2,s1,s2;
string ans1,ans2;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)for (int j=0;j<n;j++){
		if (!a[i][j]){
			x=i;
			y=j;
			continue;
		}
		while (a[i][j]%2==0)a1[i][j]++,a[i][j]/=2;
		while (a[i][j]%5==0)a2[i][j]++,a[i][j]/=5;
	}
	m1(f1);
	m1(f2);
	f1[0][0]=a1[0][0];
	f2[0][0]=a2[0][0];
	for (int i=0;i<n;i++)for (int j=0;j<n;j++){
		if (j<n-1){
			if (f1[i][j]+a1[i][j+1]<f1[i][j+1])f1[i][j+1]=f1[i][j]+a1[i][j+1],p1[i][j+1]=1;
			if (f2[i][j]+a2[i][j+1]<f2[i][j+1])f2[i][j+1]=f2[i][j]+a2[i][j+1],p2[i][j+1]=1;
		}
		if (i<n-1){
			if (f1[i][j]+a1[i+1][j]<f1[i+1][j])f1[i+1][j]=f1[i][j]+a1[i+1][j],p1[i+1][j]=2;
			if (f2[i][j]+a2[i+1][j]<f2[i+1][j])f2[i+1][j]=f2[i][j]+a2[i+1][j],p2[i+1][j]=2;
		}
	}
	xx=yy=n-1;
	as1=a1[xx][yy];
	bs1=a2[xx][yy];
	while (xx||yy){
		if (p1[xx][yy]==1)ans1="R"+ans1,yy--;else ans1="D"+ans1,xx--;
		as1+=a1[xx][yy];
		bs1+=a2[xx][yy];
	}
	xx=yy=n-1;
	as2=a1[xx][yy];
	bs2=a2[xx][yy];
	while (xx||yy){
		if (p2[xx][yy]==1)ans2="R"+ans2,yy--;else ans2="D"+ans2,xx--;
		as2+=a1[xx][yy];
		bs2+=a2[xx][yy];
	}
	s1=min(as1,bs1);
	s2=min(as2,bs2);
	if (s1>1&&s2>1&&x!=-1){
		puts("1");
		xx=yy=0;
		while (yy!=y)putchar('R'),yy++;
		while (xx!=x)putchar('D'),xx++;
		while (yy!=n-1)putchar('R'),yy++;
		while (xx!=n-1)putchar('D'),xx++;
		return 0;
	}
	if (s1<s2)cout << s1 << endl << ans1 << endl;else cout << s2 << endl << ans2 << endl;
	return 0;
}