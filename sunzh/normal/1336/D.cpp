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
int ans[110];
int dt1[110],dt2[110];
int n;
int main(){
	n=read();
	int lx,ly;
	int x=read(),y=read();
	for(int i=n-1;i>=3;--i){
		printf("+ %d\n",i);fflush(stdout);
		lx=read(),ly=read();
		dt1[i]=lx-x,dt2[i]=ly-y;x=lx,y=ly;
	}
	printf("+ 1\n");fflush(stdout);
	lx=read(),ly=read();
	dt1[2]=lx-x,dt2[2]=ly-y;x=lx,y=ly;
	printf("+ 2\n");fflush(stdout);
	lx=read(),ly=read();
	dt1[1]=lx-x,dt2[1]=ly-y;x=lx,y=ly;
	printf("+ 1\n");fflush(stdout);
	lx=read(),ly=read();
	dt1[0]=lx-x,dt2[0]=ly-y;x=lx,y=ly;
	int ls=0;ans[1]=0;
	for(int i=3;i<=n+2;++i){
		int nw=i*(i-1)*(i-2)/6;
		// if(i==4) printf("nw:%d,ls:%d,i:%d,dt:%d\n",nw,ls,i,dt1[0]);
		if(nw-ls==dt1[0]){
			ans[1]=i-2;break ;
		}
		ls=nw;
	}
	// printf("! %d\n",ans[1]);return 0;
	ans[3]=(dt2[0]-dt2[2])-1;
	ans[2]=dt2[2]/(ans[3]+1);
	ans[4]=(dt2[1]-(ans[1]+1)*(ans[3]+1))/(ans[3]+1)-(n!=4);
	for(int i=5;i<=n;++i){
		ans[i]=(dt2[i-2]-ans[i-3]*ans[i-4]-ans[i-3]*(ans[i-1]+1))/(ans[i-1]+1)-(i!=n);
	}
	printf("! ");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);printf("\n"); return 0;
}