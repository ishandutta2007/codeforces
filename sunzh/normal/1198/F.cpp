#include<ctime>
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
int a[100010];
int rk[100010];
int ans[100010];
int main(){
	double st=clock();
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),rk[i]=i;
	}
	while(clock()-st<CLOCKS_PER_SEC*0.3){
		random_shuffle(rk+1,rk+n+1);
		int g1=a[rk[1]],g2=a[rk[2]];
		ans[rk[1]]=1,ans[rk[2]]=2;
		for(int i=3;i<=n;++i){
			if(a[rk[i]]%g1!=0){
				g1=__gcd(g1,a[rk[i]]),ans[rk[i]]=1;
			}
			else{
				g2=__gcd(g2,a[rk[i]]),ans[rk[i]]=2;
			}
		}
		if(g1==g2&&g1==1){
			printf("YES\n");
			for(int i=1;i<=n;++i) printf("%d ",ans[i]);
			return 0;
		}
	}
	printf("NO\n");
}