#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 1010;

int u[N][N],d[N][N],a[N][N];
int n,m,s;

int main(){
	scanf("%d%d",&n,&m);
	fo(i,1,n){
		char ch;
		while(ch=getchar(),ch!='.'&&ch!='*');
		fo(j,1,m){
			if (ch=='*')a[i][j]=1;
			s+=a[i][j];
			ch=getchar();
		}
	}
	fo(i,1,n)
		fo(j,1,m)u[i][j]=u[i-1][j]+a[i][j];
	fd(i,n,1)
		fo(j,1,m)d[i][j]=d[i+1][j]+a[i][j];
	fo(i,1,n){
		int tot=0;
		fo(j,1,m)tot+=a[i][j];
		fo(j,1,m)
		if (u[i][j]+d[i][j]-a[i][j]*2+tot==s){
			printf("YES\n%d %d\n",i,j);
			return 0;
		}
	}
	printf("NO");
	return 0;
}