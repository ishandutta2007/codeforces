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
#define se second
#define fi first

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

const int N = 1000005;

int n,m,k;
int a[N];
int dis[N];
int f[N];

int main(){
	n=get();m=get();k=get();
	fo(i,1,n){
		int x=get();
		a[x]=1;
	}
	int sum=0,ans=0;
	fo(i,1,1000000){
		if (a[i])sum++;
		if (i>=m)sum-=a[i-m];
		if (sum>=k){
			ans=ans+sum-k+1;
			a[i]=a[i]-(sum-k+1);
			sum=k-1;
		}
	}
	printf("%d\n",ans);
	return 0;
}