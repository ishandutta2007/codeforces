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
unsigned long long a[105],b[105];
int n;
int T;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=b[i]=read();
		unsigned long long t=1;
		for(int i=1;i<=n;++i){
			while(a[i]&&a[i]%2==0){
				t<<=1;a[i]>>=1;
			}
		}
		sort(a+1,a+n+1);
		// sort(a+1,a+n+1,[&](unsigned long long x,unsigned long long y){
		// 	return mp(x&1,x)<mp(y&1,y);
		// });
		// sort(b+1,b+n+1);
		// for(int i=1;i<n;++i){
		// 	while(a[i]&&a[i]%2==0){
		// 		a[i]>>=1;a[n]<<=1;
		// 	}
		// 	while(b[i]&&b[i]%2==0){
		// 		b[i]>>=1;b[n]<<=1;
		// 	}
		// }
		unsigned long long sum=0,sum1=0;
		for(int i=1;i<=n;++i) sum+=a[i];
		printf("%llu\n",sum+(t-1)*a[n]);
	}
}