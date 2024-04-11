#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
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
int T;
int n;
int main(){
	T=read();
	while(T--){
		n=read();
		int sec=0;
		vector<int>ans;
		for(int i=2;i<=n;++i){
			printf("? %d %d\n",i-1,1);
			for(int j=1;j<i;++j) printf("%d ",j);
			printf("\n");
			printf("%d\n",i);
			fflush(stdout);
			int x=read();
			if(x){
				sec=i;break ;
			}
		}
		for(int i=sec+1;i<=n;++i){
			printf("? 1 1\n");
			printf("%d\n%d\n",sec,i);
			fflush(stdout);
			int x=read();
			if(!x) ans.pb(i);
		}
		int l=1,r=sec-1,res=0;
		while(l<=r){
			int mid=l+r>>1;
			printf("? %d %d\n",1,r-mid+1);
			printf("%d\n",sec);
			for(int i=mid;i<=r;++i) printf("%d ",i);
			printf("\n");
			fflush(stdout);
			int x=read();
			if(x) l=mid+1,res=mid;
			else r=mid-1;
		}
		for(int i=1;i<sec;++i) {
			if(i!=res) ans.pb(i);
		}
		printf("! %d ",ans.size());
		for(int i:ans) printf("%d ",i);printf("\n");fflush(stdout);
	}
}