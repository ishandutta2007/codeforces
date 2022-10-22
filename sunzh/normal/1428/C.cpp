#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
char s[200010];
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int ans=0;
		int cnt=0,fail=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='A') ++cnt;
			else{
				if(cnt) ++ans,--cnt;
				else if(fail) ++ans,--fail;
				else ++fail;
			}
		}
		printf("%d\n",n-2*ans);
	}
}