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

char s[5005];

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	fo(i,2,n)
	if (s[i]<s[i-1])return printf("NO\n"),0;
	int cnt[3];
	cnt[0]=cnt[1]=cnt[2]=0;
	fo(i,1,n)cnt[s[i]-'a']++;
	if (!cnt[0]||!cnt[1])return printf("NO\n"),0;
	if (cnt[2]==cnt[0]||cnt[2]==cnt[1])printf("YES\n");
	else printf("NO\n");
	return 0;
}