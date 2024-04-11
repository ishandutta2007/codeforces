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

const int N = 25;

int n;
int a[N],num[N],rk[N];

bool cmp(int x,int y){return a[x]<a[y];}

int main(){
	n=get();
	fo(i,1,n)a[num[i]=i]=get();
	sort(num+1,num+1+n,cmp);
	fo(i,1,n)rk[num[i]]=i;
	fo(i,1,n){
		int x=rk[i]-1;
		if (!x)x=n;
		printf("%d ",a[num[x]]);
	}
	return 0;
}