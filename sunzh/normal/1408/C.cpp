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
	if(x>10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,l;
int cnt;
int pos[100010]; 
int main(){
	T=read();
	while(T--){
		cnt=0;
		n=read(),l=read();
		pos[++cnt]=0;
		for(int i=1;i<=n;++i) pos[++cnt]=read();
		pos[++cnt]=l;
		int ps1=1,ps2=cnt;
		double t1=0.0,t2=0.0;
		int v1=1,v2=1;
		double ans=-1.0;
		while(1){
			if(ps1+1==ps2){
				if(t1>=t2){
					double rps=pos[ps2]-1.0*(t1-t2)*v2;
					ans=t1+1.0L*(rps-pos[ps1])/(v2+v1);
				}
				else{
					double lps=pos[ps1]+1.0*(t2-t1)*v1;
					ans=t2+1.0L*(pos[ps2]-lps)/(v1+v2);
				}
				break ;
			}
			double nt1=t1+1.0*(pos[ps1+1]-pos[ps1])/(1.0*v1);
			double nt2=t2+1.0*(pos[ps2]-pos[ps2-1])/(1.0*v2);
			if(nt1<=nt2){
				t1=nt1;++v1;++ps1;
			}
			else{
				t2=nt2;++v2;--ps2;
			}
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}