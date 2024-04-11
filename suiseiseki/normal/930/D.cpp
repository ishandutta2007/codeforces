#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const int eps=100001;
const int Inf=0x3f3f3f3f;
struct Node{
	int x,y;
	Node(int _x=0,int _y=0){
		x=_x,y=_y;
	}
	friend bool operator <(Node a,Node b){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.x;
	}
}a[2][Maxn+5],up[Maxn<<1|5],down[Maxn<<1|5];
int len[2];
int n;
ll work(int p){
	std::sort(a[p]+1,a[p]+1+len[p]);
	down[0]=up[0]=down[eps<<1|1]=up[eps<<1|1]=Node(Inf,0);
	for(int i=1,j=1;i<=(eps<<1);i++){
		down[i]=down[i-1];
		while(j<=len[p]&&a[p][j].x<=i){
			down[i].x=std::min(down[i].x,a[p][j].y);
			down[i].y=std::max(down[i].y,a[p][j].y);
			j++;
		}
	}
	for(int i=(eps<<1),j=len[p];i>0;i--){
		up[i]=up[i+1];
		while(j>0&&a[p][j].x>=i){
			up[i].x=std::min(up[i].x,a[p][j].y);
			up[i].y=std::max(up[i].y,a[p][j].y);
			j--;
		}
	}
	ll ans=0;
	for(int i=1;i<=(eps<<1);i++){
		int l=std::max(down[i].x,up[i+1].x),r=std::min(down[i].y,up[i+1].y);
		ans+=std::max(0,r-l);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[(x+y)&1][++len[(x+y)&1]]=Node(((x+y+1)>>1)+eps,((x-y+1)>>1)+eps);
	}
	ll ans=work(0)+work(1);
	printf("%lld\n",ans);
	return 0;
}