#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100010
using namespace std;
int n,len,ans=0;
bool is[35],in[35],now;
char s[N],tp[10];
void check(){
	if(now)return;
	int ts=0;
	rep(i,26)if(is[i]==1)++ts;
	if(ts==1)now=1;
}
int main(){
	rep(i,26)is[i]=1;now=0;
	scanf("%d",&n);
	rep(i,n-1){
		//rep(j,26)printf("%d ",is[j]);puts("");
		//printf("%d\n".
		memset(in,0,sizeof in);
		scanf("%s",tp+1);scanf("%s",s+1);len=strlen(s+1);
		if(tp[1]=='!'){
			if(now)++ans;
			rep(j,len)in[s[j]-'a'+1]=1;
			rep(j,26)if(!in[j])is[j]=0;
			check();
		}
		if(tp[1]=='.'){
			rep(j,len)in[s[j]-'a'+1]=1;
			rep(j,26)if(in[j])is[j]=0;
			check();
		}
		if(tp[1]=='?'){
			if(now)++ans;
			is[s[1]-'a'+1]=0;
			check();
		}
	}
	printf("%d\n",ans);
	return 0;
}