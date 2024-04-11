#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
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
int n;
int q;
inline int lowbit(int x){ return x&-x; }
signed main(){
	n=read();
	for(int j=1;j<=n;++j){
		for(int i=1;i<=n;++i){
			if(i&1) printf("%lld ",(1ll<<((i+1)+j-3)));
			else printf("0 ");
		}printf("\n");
	}fflush(stdout);
	q=read();
	while(q--){
		int x;scanf("%lld",&x);
//		x-=2*n-1;
//		int x=read();
		int A=1,B=1;
		printf("%d %d\n",A,B);
		int cnt=1,c=1;
		while(A<n&&B<n){
			if(x&(1ll<<c)){
//				printf("c:%d\n",c);
				if(cnt&1) ++A;
				else ++B;
			}
			else{
				if(cnt&1) ++B;
				else ++A;
			}
			++c;
			cnt=B;
			printf("%d %d\n",A,B);
		}
		while(A<n){
			++A;printf("%d %d\n",A,B);
		}
		while(B<n){
			++B;printf("%d %d\n",A,B);
		}
		fflush(stdout);
	}
	return 0;
}