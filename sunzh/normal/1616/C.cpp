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
int T;
int n;
int a[71];
const double eps=1e-9;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(n<=2){
			printf("0\n");continue ;
		}
		int ans=1;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				double d=(a[i]-a[j])*1.0l/(i-j);
				double b=a[i]-d*i;
				int res=0;
				for(int l=1;l<=n;++l){
					double tmp=d*l+b;
					if(fabs(tmp-a[l])<eps) ++res;
				}
				ans=max(ans,res);
			}
		}
		printf("%d\n",n-ans);
	}
}