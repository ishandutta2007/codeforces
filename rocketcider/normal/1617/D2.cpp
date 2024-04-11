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
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri pos0=0,pos1=0;
		for(ri i=1;i<=n;i+=3){
			a[i]=ask(i,i+1,i+2);
			(a[i]?pos1:pos0)=i;
		}
		assert(pos0&&pos1);
		ri k1=pos1+(ask(pos1,pos1+1,pos0+1)+ask(pos1,pos1+1,pos0)==2?0:2),
		   k2=pos0+(ask(pos1,pos0,pos0+1)+ask(pos1+1,pos0+1,pos0)==0?0:2);
		vector<int>v={k2};
		for(ri i=1;i<=n;i+=3)
			if(i!=pos0&&i!=pos1){
				if(a[i]){
					switch(1-ask(i,i+1,k2)+2*(1-ask(i+1,i+2,k2))){
						case 1:v.push_back(i);break;
						case 2:v.push_back(i+2);break;
						case 3:v.push_back(i+1);break;
					}
				}
				else{
					switch(ask(i,i+1,k1)+2*ask(i+1,i+2,k1)){
						case 0:v.push_back(i);v.push_back(i+1);v.push_back(i+2);break;
						case 1:v.push_back(i+1);v.push_back(i+2);break;
						case 2:v.push_back(i);v.push_back(i+1);break;
						case 3:v.push_back(i);v.push_back(i+2);break;
					}
				}
			}
			else{
				for(ri j=0;j<3;++j)
					if(i+j!=k1&&i+j!=k2&&!ask(k1,k2,i+j))
						v.push_back(i+j);
			}
		printf("! %d",(int)v.size());
		for(auto i:v)printf(" %d",i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}