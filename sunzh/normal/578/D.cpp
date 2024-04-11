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
int n,m;
char str[100010];
int main(){
	n=read(),m=read();
	scanf("%s",str+1);
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=1ll*n*(m-1);
		int j=i;
		while(j<n&&str[j+1]==str[j]) ++j;
		i=j;
	} 
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(cnt==0) ++cnt;
		else if(cnt==1){
			if(str[i]!=str[i-1]) ++cnt;
		}
		else{
			if(str[i]==str[i-2]) ++cnt;
			else{
				ans-=1ll*(cnt*(cnt-1)>>1);
				if(str[i]!=str[i-1]) cnt=2;else cnt=1;
			}
		}
	}
	ans-=1ll*cnt*(cnt-1)>>1;
	printf("%lld\n",ans);
}