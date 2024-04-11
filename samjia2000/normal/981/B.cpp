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

int n,m;
map<int,int>val;

int main(){
	n=get();
	fo(i,1,n){
		int x=get(),v=get();
		val[x]=v;
	}
	m=get();
	fo(i,1,m){
		int x=get(),v=get();
		val[x]=max(val[x],v);
	}
	LL ans=0;
	for(map<int,int>::iterator h=val.begin();h!=val.end();h++)ans=ans+(*h).second;
	cout<<ans<<endl;
	return 0;
}