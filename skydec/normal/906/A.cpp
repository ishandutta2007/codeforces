#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
bool may[27];
bool g[27];
char s[110000];
int main(){
	rep(i,0,25)may[i]=1;
	int Q;scanf("%d",&Q);
	int ans=0;
	bool ok=0;
	while(Q--){
		scanf("%s",s+1);
		if(s[1]=='!'){
			scanf("%s",s+1);
			if(ok)++ans;
			int len=strlen(s+1);
			memset(g,0,sizeof g);
			rep(i,1,len)g[s[i]-'a']=1;
			rep(i,0,25)may[i]&=g[i];
		}
		else
		if(s[1]=='?'){
			scanf("%s",s+1);
			int x=s[1]-'a';
			if(ok&&(!may[x]))++ans;
			else{
				may[x]=0;
			}
		}
		else{
			scanf("%s",s+1);
			int len=strlen(s+1);
			rep(i,1,len)may[s[i]-'a']=0;
		}
		int cnt=0;
		rep(i,0,25)if(may[i])++cnt;
		if(cnt==1)ok=1;
	}
	printf("%d\n",ans);
	return 0;
}