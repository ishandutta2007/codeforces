#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
struct seg{
	int cl[N*35],cr[N*35];
	int val[N*35];int tot;
	void init(){
		tot=1;
	}
	void del(int &me,int l,int r,int x,int y,int v){
		if(x>y)return;
		if(!me)me=++tot;
		if(x<=l&&r<=y){
			if(v>val[me])val[me]=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)del(cl[me],l,mid,x,y,v);
		if(y>mid)del(cr[me],mid+1,r,x,y,v);
	}
	int get(int me,int l,int r,int x){
		if(!me)return 0;
		if(l==r)return val[me];
		int mid=(l+r)>>1;
		if(x<=mid)return max(get(cl[me],l,mid,x),val[me]);
		else return max(get(cr[me],mid+1,r,x),val[me]);
	}
}o[2];
int n,q;
map<int,int> choose[2];
int rt=1;
int main(){
	scanf("%d%d",&n,&q);
	o[0].init();o[1].init();
	LL ans=0;
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		swap(x,y);
		char opt[3];scanf("%s",opt+1);
		if(opt[1]=='L'){
			if(choose[0][x]){
				printf("0\n");
				continue;
			}
			int u=o[0].get(1,1,n,x);
			printf("%d\n",y-u);
			o[1].del(rt,1,n,u+1,y,x);
			choose[0][x]=1;
		}
		else{
			if(choose[1][y]){
				printf("0\n");
				continue;
			}
			int u=o[1].get(1,1,n,y);
			printf("%d\n",x-u);
			o[0].del(rt,1,n,u+1,x,y);
			choose[1][y]=1;
		}
	}
	return 0;
}