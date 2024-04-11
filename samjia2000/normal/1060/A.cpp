#include<bits/stdc++.h>

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

char s[105];
int cnt[10];

int main(){
	int n=get();
	scanf("%s",s+1);
	fo(i,1,n){
		cnt[s[i]-'0']++;
	}
	int ans=0;
	fo(i,1,cnt[8]){
		cnt[8]-=i;
		int mx=0;
		fo(x,0,9)mx=max(mx,cnt[x]);
		int res=n-i-mx;
		if (n-i>=i*10)ans=i;
		cnt[8]+=i;
	}
	printf("%d\n",ans);
	return 0;
}