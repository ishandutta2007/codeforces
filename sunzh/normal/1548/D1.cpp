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
int n;
struct node{
	int x,y;
}a[6010];
int cnt[6010][4][4][4];
long long ans1,ans2;
int cross(int ax,int ay,int bx,int by){
	return ax*by-ay*bx;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(j!=i){
				int t=__gcd(abs(a[j].x-a[i].x),abs(a[j].y-a[i].y));
				cnt[i][a[j].x&3][a[j].y&3][t&3]++;
				cnt[j][a[i].x&3][a[i].y&3][t&3]++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int ax=0;ax<4;++ax){
			for(int bx=0;bx<4;++bx){
				if((ax&1)!=(bx&1)) continue ;
				for(int ay=0;ay<4;++ay){
					for(int by=0;by<4;++by){
						if((ay&1)!=(by&1)) continue ;
						for(int b1=0;b1<4;++b1){
							for(int b2=(b1&1);b2<4;b2+=2){
								long long res=0;int b3=0;
								if(ax==bx&&ay==by){
									res=(b1==b2?(1ll*cnt[i][ax][ay][b1]*(cnt[i][ax][ay][b1]-1)):1ll*cnt[i][ax][ay][b1]*cnt[i][bx][by][b2]);
								}
								else{
									b3=2;res=1ll*cnt[i][ax][ay][b1]*cnt[i][bx][by][b2];
								}
								int S=abs(cross(a[i].x&3,a[i].y&3,bx,by)+cross(bx,by,ax,ay)+cross(ax,ay,a[i].x&3,a[i].y&3));
								S>>=1;
								if((S&1)==(b1+b2+b3>>1&1)){
									if(b1&1) ans1+=res;
									else ans2+=res;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n",(ans1>>1)+ans2/6);
}