#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		int cb,cd,rb,rd;
		scanf("%d%d%d%d%d%d",&n,&m,&rb,&cb,&rd,&cd);
		int ans=0,dx=1,dy=1;
		while(rb!=rd&&cb!=cd){
			if(rb==1)dx=1;
			if(rb==n)dx=-1;
			if(cb==1)dy=1;
			if(cb==m)dy=-1;
			++ans;
			rb+=dx,cb+=dy;
		}
		printf("%d\n",ans);
	}
	return 0;
}