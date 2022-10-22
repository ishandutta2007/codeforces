#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[2000010];
int b[2000010];
signed main(){
	T=read();
	while(T--){
		n=read();
		bool flag=0;
		for(int i=1;i<=n;++i) a[i]=a[i+n]=read();
		for(int i=1;i<=n;++i) b[i]=b[i+n]=read();
		int sum=0;
		for(int i=1;i<=n;++i) sum+=a[i]-b[i];
		if(sum>0) printf("NO\n");
		else{
			sum=0;
			int minn=b[1];
			for(int i=1;i<=2*n;++i){
				sum+=a[i%n+1]-b[i%n+1];
				minn=min(minn,sum+b[i%n+1]);
				if(minn<sum){
					flag=1;break ;
				}
			}
			if(flag) printf("NO\n");
			else printf("YES\n");
		}
	}
	return 0;
}