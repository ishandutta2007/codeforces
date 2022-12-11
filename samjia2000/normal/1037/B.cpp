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

const int N = 2e5+5;

int n;
int s;
int a[N];

int main(){
	n=get();s=get();
	fo(i,1,n)a[i]=get();
	sort(a+1,a+1+n);
	LL ans=0;
	fo(i,1,n/2)ans=ans+max(0,a[i]-s);
	ans=ans+abs(a[n/2+1]-s);
	fo(i,n/2+2,n)ans=ans+max(0,s-a[i]);
	cout<<ans<<endl;
	return 0;
}