#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn];
inline int ask(int x,int y,int z){
	if(y==x+1&&z==x+2&&a[x]!=-1)return a[x];
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	if(y==x+1&&z==x+2)a[x]=ret;
	return ret;
}
int ans[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)a[i]=ans[i]=-1;
		ri pos1=0,pos2=0;
		for(ri i=1;i+3<=n;++i)
			if(ask(i,i+1,i+2)!=ask(i+1,i+2,i+3)){
				pos1=i,pos2=i+3;
				break;
			}
		assert(pos1&&pos2);
		for(ri i=1;i<=n;++i)
			if(i!=pos1&&i!=pos2)
				ans[i]=ask(pos1,pos2,i);
		for(ri i=1;i<=n;++i)
			if(ans[i]==0)
				for(ri j=1;j<=n;++j)
					if(ans[j]==1){
						ans[pos1]=ask(i,j,pos1);
						ans[pos2]=ask(i,j,pos2);
						goto skip;
					}
		skip:;
		vector<int>v;
		for(ri i=1;i<=n;++i)
			if(ans[i]==0)
				v.push_back(i);
		printf("! %d",(int)v.size());
		for(auto i:v)printf(" %d",i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}