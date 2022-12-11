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

int cnt[100];

int main(){
	int k=get();
	if (k==0){
		putchar('a');
		return 0;
	}
	k=k*2;
	int w=0;
	fd(i,k,2)
	while (1ll*i*(i-1)<=k){
		cnt[w++]=i;
		k=k-i*(i-1);
	}
	fo(i,0,25)fo(j,1,cnt[i])putchar('a'+i);
	return 0;
}