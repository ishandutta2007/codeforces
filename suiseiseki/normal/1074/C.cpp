#include <cstdio>
#include <algorithm>
const int Maxn=300000;
const int Inf=0x3f3f3f3f;
int n;
struct Node{
	int x,y;
}a[Maxn+5];
int calc_ans(int x,int y,Node a){
	int max_x=std::max(x,a.x),max_y=std::max(y,a.y);
	int min_x=std::min(x,a.x),min_y=std::min(y,a.y);
	return (max_x-min_x+max_y-min_y)*2;
}
int main(){
	scanf("%d",&n);
	int min_x=Inf,max_x=-Inf,min_y=Inf,max_y=-Inf;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		min_x=std::min(min_x,a[i].x),max_x=std::max(max_x,a[i].x);
		min_y=std::min(min_y,a[i].y),max_y=std::max(max_y,a[i].y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=std::max(ans,calc_ans(min_x,min_y,a[i]));
		ans=std::max(ans,calc_ans(min_x,max_y,a[i]));
		ans=std::max(ans,calc_ans(max_x,min_y,a[i]));
		ans=std::max(ans,calc_ans(max_x,max_y,a[i]));
	}
	printf("%d ",ans);
	ans=(max_x-min_x+max_y-min_y)*2;
	for(int i=4;i<=n;i++){
		printf("%d ",ans);
	}
	puts("");
	return 0;
}