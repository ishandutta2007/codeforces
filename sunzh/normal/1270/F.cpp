#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<unordered_map>
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
inline void print(long long x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int pre[200010];
char s[200010];
int pos[200010];
int idx[200010];
int n;
long long ans;
int cnt;
	int ma[90000010];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int T=sqrt(n);
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+(s[i]-'0');
	for(int i=1;i<=T;++i){
		ma[n*T]=1;
		for(int j=1;j<=n;++j){
			int x=j-i*pre[j];
			ans+=ma[x+n*T],++ma[x+n*T]; 
//			printf("%d ",x);
		}
		for(int j=1;j<=n;++j){
			int x=j-i*pre[j];
			ma[x+n*T]--;
		}
//		printf("\n");
	} 
	cnt=1;
	for(int i=1;i<=n;++i){
		idx[i]=cnt;
		if(s[i]=='1') pos[cnt++]=i;
	}
	pos[cnt]=n+1;
//	printf("t:%d\n",T);
	for(int i=1;i<=n;++i){
//		printf("%d %d\n",n-i,(n-i)/T);
		for(int j=1;j<=((n-i)/T)&&j+idx[i]<=cnt;++j){
			int rmax=pos[idx[i]+j]-1;
			int r=max(pos[idx[i]+j-1]-1,i+j*T-1);
//			printf("i:%d,j:%d,rmax:%d,r:%d\n",i,j,rmax,r);
			ans+=max(0,(rmax-i+1)/j-(r-i+1)/j);
//			printf("%d\n",ans);
		}
	}
	print(ans);
}