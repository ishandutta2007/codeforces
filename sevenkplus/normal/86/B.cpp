#include<cstdio>
int n,m;char a[1111][1111];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			if(a[i][j]=='.'&&a[i][j+1]=='.')
				a[i][j]=a[i][j+1]=(((i+j)&1)?('0'+(i%3*3+(j+1)%3)):('0'+(i%3*3+j%3)));
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='.'&&a[i+1][j]=='.')
				a[i][j]=a[i+1][j]=(((i+j)&1)?('0'+((i+1)%3*3+j%3)):('0'+(i%3*3+j%3)));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='.')
			{
				if(i>0&&a[i-1][j]!='#'){a[i][j]=a[i-1][j];continue;}
				if(j>0&&a[i][j-1]!='#'){a[i][j]=a[i][j-1];continue;}
				if(i<n-1&&a[i+1][j]!='#'){a[i][j]=a[i+1][j];continue;}
				if(j<m-1&&a[i][j+1]!='#'){a[i][j]=a[i][j+1];continue;}
				puts("-1");return 0;
			}
	for(int i=0;i<n;i++)printf("%s\n",a[i]);
	return 0;
}