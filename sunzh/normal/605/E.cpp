#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
int p[1010][1010];
bool vis[1010];
double E[1010],pd[1010];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) p[i][j]=read();
	}
	for(int i=1;i<n;++i){
		pd[i]=1-p[i][n]/100.0l;
	}
//	for(int i=1;i<n;++i) printf("%.5lf ",pd[i]);
	for(int i=1;i<n;++i) E[i]=1;
	if(n==1){
		printf("0.00000000\n");return 0;
	}
	for(int t=1;t<n;++t){
		int pos=0;double mn=1e18;
		for(int i=1;i<n;++i){
			if(!vis[i]&&E[i]/(1-pd[i])<mn) mn=E[i]/(1-pd[i]),pos=i;
		}
//		printf("t:%d,pos:%d\n",t,pos);
		if(pos==1){
//			printf("%.3lf\n",E[pos]);
			printf("%.10lf\n",E[pos]/(1-pd[pos]));
			return 0;
		}
//		printf("t:%d,pos:%d,E:%.3lf\n",t,pos,(E[pos]+1)/(1-pd[pos])-1.0);
		vis[pos]=1;
		double G=E[pos]/(1-pd[pos]);
		for(int j=1;j<n;++j){
			if(!vis[j]){
				E[j]+=G*p[j][pos]/100.0l*pd[j];
				pd[j]=pd[j]*(1-p[j][pos]/100.0l);
//				printf("pos:%d,j:%d,%.4lf\n",pos,j,pd[j]);
			}
		}
	}
}