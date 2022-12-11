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

int main(){
	int ans[100],t=0;
	int n=get();
	while(n){
		int q=1;
		while(q*10<=n){q*=10;}
		int n_=n;
		ans[++t]=0;
		for(;q;q/=10){
			if (n_>=q)ans[t]+=q;
			n_%=q;
		}
		n=n-ans[t];
	}
	printf("%d\n",t);
	fo(i,1,t)printf("%d ",ans[i]);
	return 0;
}