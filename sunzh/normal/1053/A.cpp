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
#define int long long
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,k;
signed main(){
	n=read(),m=read(),k=read();
	long long T=1ll*n*m;
	long long g=__gcd(T,k);
	T/=g;k/=g;
	if(k>2) puts("NO");
	else{
		if(k==1) {
			long long tmp=__gcd(n*2,g);
			g/=tmp;
			if(tmp>=2){
				puts("YES");
				printf("%lld 0\n0 %lld\n0 0 \n",n*2/tmp,m/g);
			}
			else if(g>2){
				puts("YES");
				printf("%lld 0\n0 %lld\n0 0 \n",n/tmp,m/g*2);
			}
			else puts("NO");
		}
		else{
			long long tmp=__gcd(n,g);
			g/=tmp;
			puts("YES");
			printf("%lld 0\n0 %lld\n0 0 \n",n/tmp,m/g);
		}
	}
}