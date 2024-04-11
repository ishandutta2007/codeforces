#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e6+5;

int n;
char s[N];
int a[N],b[N];
int f[N][2];

int main(){
	n=get();
	scanf("%s",s+1);
	fo(i,1,n)a[i]=s[i]-'0';
	scanf("%s",s+1);
	fo(i,1,n)b[i]=s[i]-'0';
	fo(i,1,n)f[i][0]=f[i][1]=1e9;
	f[1][a[1]]=0;
	f[1][a[1]^1]=1;
	fo(i,1,n-1){
		int v=a[i+1];
		fo(j,0,1){
			//no moves
			if (j==b[i])f[i+1][v]=min(f[i+1][v],f[i][j]);
			//operate 1
			if (v==b[i])f[i+1][j]=min(f[i+1][j],f[i][j]+1);
			//oeprate 2
			if (j==b[i])f[i+1][v^1]=min(f[i+1][v^1],f[i][j]+1);
		}
	}
	cout<<f[n][b[n]]<<endl;
	return 0;
}