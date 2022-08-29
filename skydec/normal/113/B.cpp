#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 2005
char str[MAXN];
char be[MAXN],ed[MAXN];
bool isbe[MAXN],ised[MAXN];
int n;int lbe,led;
bool cao[MAXN*MAXN];
int go[2005000][26];int tot=1;
int main()
{
	scanf("%s",str+1);n=strlen(str+1);
	scanf("%s",be+1);lbe=strlen(be+1);
	scanf("%s",ed+1);led=strlen(ed+1);
	rep(i,1,n-lbe+1){
		isbe[i]=1;
		rep(j,1,lbe)if(str[i+j-1]!=be[j])isbe[i]=0;
	}
	rep(i,led,n){
		ised[i]=1;
		rep(j,1,led)if(ed[j]!=str[i-led+j])ised[i]=0;
	}
	rep(i,1,n)if(isbe[i]){
		int now=1;
		rep(j,i,n){
			if(!go[now][str[j]-'a'])go[now][str[j]-'a']=++tot;
			now=go[now][str[j]-'a'];
			if(ised[j]&&j-i+1>=led&&j-i+1>=lbe)cao[now]=1;
		}
	}
	int ans=0;
	rep(i,1,tot)ans+=cao[i];
	printf("%d\n",ans);
}