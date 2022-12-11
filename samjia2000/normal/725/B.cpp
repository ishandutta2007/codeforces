#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;

LL n;
char ch;
int v[6]={4,5,6,3,2,1};

int main(){
	while(ch=getchar(),ch<'0'||ch>'9');
	n=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')n=n*10+ch-'0';
	printf("%I64d\n",((n-1)/4)*16+(1-n%2)*7+v[ch-'a']);
	return 0;
}