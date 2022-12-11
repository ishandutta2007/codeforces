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

const int N = 505;
const int mo = 1e9+7;

int fl[N];

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

int main(){
	int n=get();
	LL ans=0;
	fo(i,1,n){
		int x=get();
		if (x!=-1)fl[x]++;
	}
	fo(i,1,n)
	if (fl[i]>0){
		ans=(ans+quickmi(2,fl[i])-1)%mo;
	}
	ans=((quickmi(2,n-1)-1-ans)%mo+mo)%mo;
	cout<<ans<<endl;
	return 0;
}