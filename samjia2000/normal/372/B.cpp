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

const int N = 42;

int n,m,q;
int a[N][N];
char s[N];
int sta[N],top;
int up[N];

int main(){
	n=get();m=get();q=get();
	fo(i,1,n){
		scanf("%s",s+1);
		fo(j,1,m)a[i][j]=(s[j]=='1');
	}
	fo(cas,1,q){
		int lx=get(),ly=get(),rx=get(),ry=get();
		fo(i,ly,ry)up[i]=0;
		int ans=0;
		fo(i,lx,rx){
			fo(j,ly,ry)up[j]=a[i][j]?0:up[j]+1;
			top=0;
			sta[0]=ly-1;
			fo(j,ly,ry){
				while(top&&up[sta[top]]>=up[j]){
					ans=ans+up[sta[top]]*(j-sta[top])*(sta[top]-sta[top-1]);
					top--;
				}
				sta[++top]=j;
			}
			while(top){
				ans=ans+up[sta[top]]*(ry-sta[top]+1)*(sta[top]-sta[top-1]);
				top--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}