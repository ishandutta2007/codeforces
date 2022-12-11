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

const int N = 1e5+5;

int n;
int a[N*2];

int main(){
	n=get();
	fo(i,1,n*2)a[i]=get();
	sort(a+1,a+1+n*2);
	LL ans=1ll*(a[n]-a[1])*(a[n*2]-a[n+1]);
	fo(i,n+1,n*2-1){
		int w=i-n;
		int low=a[i-w];
		LL tmp=1ll*(a[i]-a[1])*(a[n*2]-low);
		if (tmp<ans)ans=tmp;
	}
	fo(i,2,n){
		LL tmp=1ll*(a[i+n-1]-a[i])*(a[n*2]-a[1]);
		if (tmp<ans)ans=tmp;
	}
	cout<<ans<<endl;
	return 0;
}