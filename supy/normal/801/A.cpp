#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
char s[105]; int l,ans;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int getans(int p) {
	s[p]=(s[p]=='V') ? 'K' : 'V';
	int cnt=0;
	rep(i,1,l-1) if (s[i]=='V'&&s[i+1]=='K') cnt++;
	s[p]=(s[p]=='V') ? 'K' : 'V';
	return cnt;
}
int main()
{
	scanf("%s",s+1); l=strlen(s+1);
	rep(i,0,l) ans=max(ans,getans(i));
	printf("%d",ans);
	return 0;
}