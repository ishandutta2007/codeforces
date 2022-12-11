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
const LL INF = 1e16;

int n,k;
int a[N],b[N];
int d[N];

int main(){
	n=get();
	int k1=get(),k2=get();
	k=k1+k2;
	fo(i,1,n)a[i]=get();
	fo(i,1,n)b[i]=get();
	fo(i,1,n)d[i]=abs(a[i]-b[i]);
	fo(i,1,k){
		int mx=0,key=0;
		fo(x,1,n)
		if (!key||mx<d[x]){
			mx=d[x];
			key=x;
		}
		if (mx==0){k=k-i+1;break;}
		d[key]--;
		if (i==k){k=0;break;}
	}
	LL ans=k&1;
	fo(i,1,n)ans=ans+1ll*d[i]*d[i];
	cout<<ans<<endl;
	return 0;
}