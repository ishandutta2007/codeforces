#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n,t_case,x=8;
int query(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
inline int lowbit(int k){return k&-k;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		int ans=0;
		for(ri i=0;i<30;++i)
			if(query((1<<i)-ans,(3ll<<i)-ans)==(1<<(i+1)))
				ans|=(1<<i);
		printf("! %d\n",ans);
		fflush(stdout);
	}
	return 0;
}