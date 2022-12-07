#include<stdio.h>
int n,m,p1[555555][2],p2[555555][2],ans=1,x,y;
int main(){
	scanf("%d%d\n",&n,&m);
	char a[n+3][m+3];
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]!='.'){
		x=(a[i][j]<'2')||(a[i][j]>'3');
		y=i%2;
		p1[j][x^y]=1;
		x=a[i][j]<'3';
		y=j%2;
		p2[i][x^y]=1;
	}
	for (int i=0;i<m;i++)ans=(ans*(2-p1[i][0]-p1[i][1]))%1000003;
	for (int i=0;i<n;i++)ans=(ans*(2-p2[i][0]-p2[i][1]))%1000003;
	printf("%d\n",ans);
	return 0;
}