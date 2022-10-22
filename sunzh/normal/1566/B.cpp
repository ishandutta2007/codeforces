#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
char str[100010];
int nxt[100010][3];
int suf[100010];
int main(){
	int T=read();
	while(T--){
		scanf("%s",str+1);
		int n=strlen(str+1);
		nxt[n+1][0]=nxt[n+1][1]=n+1;
		for(int i=n;i>=1;--i){
			nxt[i][0]=nxt[i+1][0],nxt[i][1]=nxt[i+1][1];
			nxt[i][str[i]-'0']=i;
		}
		suf[n+1]=0;
		for(int i=n;i>=1;--i) {
			suf[i]=suf[i+1];
			if(nxt[i][suf[i]]!=n+1) ++suf[i];
		}
		bool o0=0,o1=0;
		int pre=0;
		int ans=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(str[i]-'0'==0){
				int j=i;
				while(str[j+1]==str[i]) ++j;
				i=j;++cnt;
			}
		}
		if(cnt==0) printf("0\n");
		else if(cnt==1) printf("1\n");
		else printf("2\n");
		// printf("%d\n",ans);
	}
}