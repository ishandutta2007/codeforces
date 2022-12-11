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

LL f[N];
int n,k;

LL calc(int n,int m){
	m=min(m,n-m);
	LL ans=1;
	fd(i,n,n-m+1)ans=ans*i;
	fo(i,1,m)ans=ans/i;
	return ans;
}

LL js(int n){
	LL ans=1;
	fo(i,1,n)ans=ans*i;
	return ans;
}

int main(){
	n=get();k=get();
	f[n]=1;
	fd(i,n-1,n-k){
		f[i]=calc(n,i)*js(n-i);
		fo(j,i+1,n)f[i]=f[i]-f[j]*calc(j,i);
	}
	LL ans=0;
	fo(i,n-k,n)ans=ans+f[i];
	printf("%I64d\n",ans);
	return 0;
}