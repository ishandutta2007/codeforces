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

char s[55];

int n;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	fo(i,1,n)
		fo(j,i,n){
			bool pd=1;
			fo(l,0,j-i)pd&=(s[i+l]==s[j-l]);
			if (!pd)ans=max(ans,j-i+1);
		}
	printf("%d\n",ans);
	return 0;
}