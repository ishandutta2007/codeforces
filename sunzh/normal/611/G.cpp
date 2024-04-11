#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<cassert>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
const int mod=1e9+7;
int n;
struct node{
	__int128 x,y;
	bool operator <(const node &rhs)const{
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
}a[500010],ke[1000010],s[1000010];
node operator -(const node &x,const node &y){
	return node{x.x-y.x,x.y-y.y};
}
node operator +(const node &x,const node &y){
	return node{x.x+y.x,x.y+y.y};
}
__int128 operator *(const node &x,const node &y){
	return 1ll*x.x*y.y-1ll*x.y*y.x;
}
int stk[500010];
int top,cnt;
int mpre[1000010],spre[1000010];
const int inv2=(mod+1>>1);
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		while(top>1&&(a[i]-a[stk[top-1]])*(a[stk[top]]-a[stk[top-1]])>=0) --top;
		stk[++top]=i;
	}
	for(int i=1;i<=top;++i) ke[++cnt]=a[stk[i]];
	top=0;
	for(int i=n;i>=1;--i){
		while(top>1&&(a[i]-a[stk[top-1]])*(a[stk[top]]-a[stk[top-1]])>=0) --top;
		stk[++top]=i;
	}
	for(int i=2;i<=top;++i) ke[++cnt]=a[stk[i]];
	assert(cnt!=n);
	for(int i=1;i<=n;++i) ke[i+n]=ke[i];
	__int128 S=0,All=0,S1=0;
	for(int i=1;i<=n;++i){
		All+=ke[i]*ke[i+1==n+1?1:i+1];
	} 
	s[1]=ke[1];
	for(int i=2;i<=n+n;++i){
		s[i]=ke[i]+s[i-1];
		__int128 x=ke[i-1]*ke[i];
		mpre[i]=(mpre[i-1]+x%mod)%mod;
		spre[i]=(spre[i-1]+mpre[i])%mod;
	}
	int it=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		while(it<i+n&&S+ke[i]*ke[it]+ke[it]*ke[it+1]+ke[it+1]*ke[i]<=(All>>1)){
			S+=ke[i]*ke[it]+ke[it]*ke[it+1]+ke[it+1]*ke[i];
			++it;
		}
//		printf("i:%d,it:%d\n",i,it);
		if(i!=it){
			S1=(spre[it]-spre[i]-1ll*mpre[i]%mod*(it-i)%mod+(s[it]-s[i])*ke[i]%mod)%mod;
			S1=(S1+mod)%mod;
//			printf("S1:%d\n",S1);
			(ans+=(1ll*All%mod*(it-i-1)%mod-2ll*S1%mod+mod)%mod)%=mod;
			S+=ke[i]*ke[it]+ke[i+1]*ke[i]+ke[it]*ke[i+1];
		}
	}
	printf("%d\n",ans);
}