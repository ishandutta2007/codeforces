#include<bits/stdc++.h>

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

const int N = 1e5+5;

int k,key[N];
int f[N];
int a[N];
int n;
int w[N];

int main(){
	n=get();
	fo(i,1,n){
		a[i]=get();
		w[a[i]]=i;
	}
	fd(i,n,1){
		int x=w[i];
		f[x]=0;
		for(int y=x+i;y<=n;y+=i)if (a[y]>a[x]&&!f[y])f[x]=1;
		for(int y=x-i;y>0;y-=i)if (a[y]>a[x]&&!f[y])f[x]=1;
	}
	fo(i,1,n)if (f[i])putchar('A');else putchar('B');
	putchar('\n');
	return 0;
}