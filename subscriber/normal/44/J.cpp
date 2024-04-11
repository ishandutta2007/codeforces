#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>

using namespace std;

int n,m,f[1111][1111],g[5];
char a[1111][1111];

void o(int x,int y){
	if (f[x-1][y])g[a[x-1][y]-'a']=1;
	if (f[x+1][y])g[a[x+1][y]-'a']=1;
	if (f[x][y-1])g[a[x][y-1]-'a']=1;
	if (f[x][y+1])g[a[x][y+1]-'a']=1;
}

void check(int x,int y){
	if (x<=0||x>n||y<=0||y>m||a[x][y]!='b'||f[x][y])return;
	int f1=a[x-1][y]!='w'||a[x+1][y]!='w';
	int f2=a[x][y-1]!='w'||a[x][y+1]!='w';
	if (f1&&f2){
		puts("NO");
		exit(0);
	}
	if (f1){
		memset(g,0,sizeof(g));
		o(x,y);
		o(x,y-1);
		o(x,y+1);
		char k;
		for (int i=3;i>=0;i--)if (!g[i])k=i+'a';
		f[x][y]=1;
		f[x][y-1]=1;
		f[x][y+1]=1;
		a[x][y]=k;
		a[x][y-1]=k;
		a[x][y+1]=k;
		check(x,y-2);
		check(x,y+2);
		check(x-1,y-1);
		check(x-1,y+1);
		check(x+1,y-1);
		check(x+1,y+1);
		check(x-1,y);
		check(x+1,y);
				
	}
	if (f2){
		memset(g,0,sizeof(g));
		o(x,y);
		o(x-1,y);
		o(x+1,y);
		char k;
		for (int i=3;i>=0;i--)if (!g[i])k=i+'a';
		a[x][y]=k;
		a[x-1][y]=k;
		a[x+1][y]=k;
		f[x][y]=1;
		f[x-1][y]=1;
		f[x+1][y]=1;
		check(x-2,y);
		check(x+2,y);
		check(x-1,y-1);
		check(x-1,y+1);
		check(x+1,y-1);
		check(x+1,y+1);
		check(x,y-1);
		check(x,y+1);
				
	}
}                           

int main(void){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d\n",&n,&m);			
	for (int i=1;i<=n;i++){
		gets(a[i]);
		for (int j=m;j;j--)a[i][j]=a[i][j-1];
		a[i][0]='.';
	}
	for (int i=1;i<=m;i++)a[0][i]='.';
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)check(i,j);
	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)if (a[i][j]!='.'&&f[i][j]==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)putchar(a[i][j]);
		puts("");
	}
	return 0;
}