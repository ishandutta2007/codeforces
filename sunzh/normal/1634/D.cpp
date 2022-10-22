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
int T,n;
int qry(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z);fflush(stdout);
	return read();
}
int main(){
	T=read();
	while(T--){
		n=read();
		int x=-1,pos=0;
		for(int i=3;i<=n;++i){
			printf("? %d %d %d\n",1,2,i);fflush(stdout);
			int t=read();
			if(t>x) x=t,pos=i;
		}
		int mx=-1,op=0;
		for(int i=3;i<=n;++i) if(i!=pos){
			printf("? %d %d %d\n",1,pos,i);fflush(stdout);
			int t=read();
			if(t>mx) mx=t,op=i;
		}
		int o1=qry(1,2,op),o2=x,o3=mx,o4=qry(2,op,pos);
		int t=max(o1,max(o2,max(o3,o4)));
		if(t==o1&&t==o3) printf("! %d %d\n",1,op);
		else if(t==o1&&t==o2) printf("! 1 2\n");
		else if(t==o1&&t==o4) printf("! 2 %d\n",2,op);
		else if(t==o2&&t==o3) printf("! 1 %d\n",pos);
		else if(t==o2&&t==o4) printf("! 2 %d\n",pos);
		else if(t==o3&&t==o4) printf("! %d %d\n",op,pos);
		fflush(stdout);
	}
}