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

int n,m;
char s[N],t[N];

int main(){
	n=get();m=get();
	scanf("%s",s+1);
	scanf("%s",t+1);
	int w=0;
	fo(i,1,n)
	if (s[i]=='*'){w=i;break;}
	if (!w){
		bool pd=(n==m);
		if (pd)
			fo(i,1,n)pd&=(s[i]==t[i]);
		if (pd)printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int l=w-1,r=n-w;
	bool ans=0;
	if (m>=n-1){
		ans=1;
		fo(i,1,l)ans&=(s[i]==t[i]);
		fo(i,1,r)ans&=(s[n-i+1]==t[m-i+1]);
	}
	if (ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}