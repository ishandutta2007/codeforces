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
int query(int x,int y){
	printf("? %d %d\n",x,y);fflush(stdout);return read();
}
int main(){
	T=read();
	while(T--){
		int ans=0;
		for(int i=0;i<30;++i){
			if(query((1<<i+1)+(1<<i)-ans,(1<<i)-ans)==(1<<i+1)){
				ans+=(1<<i);
			}
			// printf("ans:%d\n",ans);
		}
		printf("! %d\n",ans);fflush(stdout);
	}
}