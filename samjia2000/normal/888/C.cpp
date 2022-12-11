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

const int N = 100005;

char s[N];
int n;
int cnt[30];
bool bz[30];

bool check(int l){
	fo(i,0,25)cnt[i]=0,bz[i]=1;
	fo(i,1,l-1)cnt[s[i]-'a']++;
	fo(i,l,n){
		if (i>l)cnt[s[i-l]-'a']--;
		cnt[s[i]-'a']++;
		fo(x,0,25)if (!cnt[x])bz[x]=0;
	}
	fo(i,0,25)if (bz[i])return 1;
	return 0;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}