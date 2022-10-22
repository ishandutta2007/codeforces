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
int n;
int p[200010];
struct BIT{
	long long t[200010];
	void insert(int x,int k){
		while(x<=n){
			t[x]+=k;
			x+=x&-x;
		}
	}
	long long query(int x){
		long long res=0;
		while(x){
			res+=t[x];
			x-=x&-x;
		}
		return res;
	}
	int bs(int k){
		int res=0;
		for(int i=20;i>=0;--i){
			if(n>=(res|(1<<i))){
				if(t[res|(1<<i)]<=k){
					res|=(1<<i),k-=t[res];
				}
			}
		}
		return res;
	}
}A,B;
long long ans1,ans2;
int pos[200010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) p[i]=read(),pos[p[i]]=i;
	for(int i=1;i<=n;++i){
		A.insert(pos[i],1);
		ans1+=i-A.query(pos[i]);
		B.insert(pos[i],pos[i]);
		int j=A.bs(i>>1);
//		printf("j:%d\n",j);
		ans2=1ll*(j-(i>>1)+1+j)*(i>>1)>>1;
		ans2-=B.query(j);
		ans2+=B.query(n)-B.query(j);
		ans2-=1ll*(j+1+(i-(i>>1))-1+j+1)*(i-(i>>1))>>1;
//		printf("%d\n",ans2);
		printf("%lld ",ans1+ans2);
	} 
	return 0;
}