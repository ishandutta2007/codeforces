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
int a[100010];
int query(int x){
	printf("? %d\n",x+1);fflush(stdout);
	return read();
}
int main(){
	n=read();
	if(n&1){
		printf("! -1\n");return 0;
	}
	if((n>>1)&1){
		printf("! -1\n");return 0;
	}
	a[0]=query(0);a[(n>>1)]=query((n>>1));
	int dt=a[(n>>1)]-a[0];
	if(dt==0){
		printf("! 1\n");return 0;
	}
	else if(dt<0){
		int l=1,r=(n>>1)-1,res=1;
		while(l<=r){
			int mid=l+r>>1;
			int x=query(mid),y=query((mid+(n>>1))%n);
			if(y-x==0){
				res=mid;break ;
			}
			if(y-x<0) l=mid+1;else r=mid-1;
		}
		printf("! %d\n",res+1);
	}
	else {
		int l=1,r=(n>>1)-1,res=1;
		while(l<=r){
			int mid=l+r>>1;
			int x=query(mid),y=query((mid+(n>>1))%n);
			if(y-x==0){
				res=mid;break ;
			}
			if(y-x>0) l=mid+1;else r=mid-1;
		}
		printf("! %d\n",res+1);
	}
}