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

const int N = 1005;

int n,r;
int a[N];
db w[N];

int main(){
	n=get();r=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n){
		w[i]=r;
		fo(j,1,i-1)
		if (abs(a[i]-a[j])<=r*2){
			db delt=sqrt(1.0*r*r*4-(a[i]-a[j])*(a[i]-a[j]));
			db v=w[j]+delt;
			if (v>w[i])w[i]=v;
		}
		printf("%.9lf ",w[i]);
	}
	putchar('\n');
	return 0;
}