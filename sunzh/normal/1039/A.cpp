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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,t;
int a[200010],X[200010],b[200010];
signed main(){
	n=read(),t=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) X[i]=read();
	for(int i=1;i<=n;++i) if(X[i]<i||X[i]<X[i-1]){
		printf("No\n");exit(0);
	}
	// if(n==100) printf("hh");
	int lstp=1;
	for(int i=2;i<=n;++i) if(X[i]!=X[i-1]){
		if(X[i-1]!=i-1){
			// if(n==100) printf("%d,%d\n",X[i-1],i-1);
			printf("No\n");exit(0);
		}
		// printf("i:%d,lst:%d,%d,%d\n",i,lstp,a[X[i-1]]+t,a[X[i]]+t);
		// if(a[X[i-1]]+t+(i-lstp-1)>=a[X[i]]+t){
		// 	printf("No\n");exit(0);
		// }
		lstp=i;
	}
	for(int i=1;i<=n;++i) b[i]=max(a[i==X[i]?i:i+1]+t,b[i-1]+1);
	for(int i=1;i<n;++i) if(X[i]==i){
		if(b[i]>=a[i+1]+t){
			printf("No\n");exit(0);
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;++i) printf("%lld ",b[i]);
}