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

int n,m,k,a[2222][2222];
char e[3333][3333];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d%d\n",&n,&m,&k);
	for (int i=0;i<n+n-1;i++)gets(e[i]);
	if (k==1){
		int b=0,a=0;
		for (int i=0;i<n+n-1;i++)for (int j=0;e[i][j];j++){
			b++;
			if (e[i][j]=='E')a++;
		}
		if (a*4<b*3)puts("NO");else{
			puts("YES");
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++)printf("1 ");
				puts("");
			}
		}
		return 0;
	}
	if (n<=m){
		a[0][0]=1;
		for (int i=1;i<m;i++)if (e[0][i-1]=='E')a[0][i]=a[0][i-1];else a[0][i]=3^a[0][i-1];
		for (int i=1;i<n;i++){
			a[i][0]=1;
			for (int j=1;j<m;j++)if (e[i+i][j-1]=='E')a[i][j]=a[i][j-1];else a[i][j]=3^a[i][j-1];
			int o=0;
			for (int j=0;j<m;j++){
				if (e[i+i-1][j]=='E'&&a[i][j]!=a[i-1][j])o++;
				if (e[i+i-1][j]=='N'&&a[i][j]==a[i-1][j])o++;
			}
			if (o+o>m)for (int j=0;j<m;j++)a[i][j]^=3;
		}
	}else{
		a[0][0]=1;
		for (int i=1;i<n;i++)if (e[i+i-1][0]=='E')a[i][0]=a[i-1][0];else a[i][0]=3^a[i-1][0];
		for (int i=1;i<m;i++){
			a[0][i]=1;                         
			for (int j=1;j<n;j++)if (e[j+j-1][i]=='E')a[j][i]=a[j-1][i];else a[j][i]=3^a[j-1][i];
			int o=0;
			for (int j=0;j<n;j++){
				if (e[j+j][i-1]=='E'&&a[j][i]!=a[j][i-1])o++;
				if (e[j+j][i-1]=='N'&&a[j][i]==a[j][i-1])o++;

			}
			if (o+o>n)for (int j=0;j<n;j++)a[j][i]^=3;
		}
	}
	puts("YES");
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}