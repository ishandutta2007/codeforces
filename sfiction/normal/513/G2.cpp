/*
ID: Sfiction
OJ: CF
PROB: 513B2
*/
#include <cstdio>

const int MAXN=35,MAXK=210;

int n,m;
int a[MAXN];
double p[MAXK][MAXN][MAXN];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	double p0=2.0/(n*(n+1));
	for (int k=1;k<=m;++k){
		for (int i=1;i<n;++i)
			for (int j=i+1;j<=n;++j){
				for (int x=1;x<=n;++x)
					for (int y=x;y<=n;++y)
						if (x<=i){
							if (y<i)
								p[k][i][j]+=p[k-1][i][j];
							else if (y<j)
								p[k][i][j]+=p[k-1][x+y-i][j];
							else
								p[k][i][j]+=1-p[k-1][x+y-j][x+y-i];
						}
						else if (x<=j){
							if (y<j)
								p[k][i][j]+=p[k-1][i][j];
							else
								p[k][i][j]+=p[k-1][i][x+y-j];
						}
						else
							p[k][i][j]+=p[k-1][i][j];
				p[k][i][j]*=p0;
			}
	}
	double ans=0;
	for (int i=1;i<n;++i)
		for (int j=i+1;j<=n;++j)
			if (a[i]<a[j])
				ans+=p[m][i][j];
			else
				ans+=1-p[m][i][j];
	printf("%.12f",ans);
	return 0;
}