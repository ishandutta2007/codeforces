#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	bool pd=0;
	int s=ch-'0';
	if (ch=='-'){pd=1;s=0;}
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (pd)return -s;
	else return s;
}

const int N = 100010;

bool r[N],c[N];
int tc,tr;
int n,m;

int main(){
	n=get();m=get();
	LL now=LL(n)*n;
	fo(i,1,m){
		int x=get(),y=get();
		if (!r[x]){
			now-=n-tc;
			if (!c[y])now++;
		}
		if (!c[y]){
			now-=n-tr;
			if (!r[x])now++;
		}
		if (!c[y]&&!r[x])now--;
		if (!c[y]){c[y]=1;tc++;}
		if (!r[x]){r[x]=1;tr++;}
		printf("%I64d ",now);
	}
	putchar('\n');
	return 0;
}