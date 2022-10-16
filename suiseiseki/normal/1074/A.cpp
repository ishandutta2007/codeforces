#include <cstdio>
#include <algorithm>
const int Maxn=100000;
const int Maxv=1000000000;
int n,m;
int lis_y_len;
int lis_x[Maxn+5],lis_y[Maxn+5];
struct Segment{
	int y;
	int x_1,x_2;
}seg[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&lis_x[i]);
	}
	std::sort(lis_x+1,lis_x+1+n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&seg[i].x_1,&seg[i].x_2,&seg[i].y);
	}
	std::sort(seg+1,seg+1+m,[&](Segment a,Segment b){return a.y==b.y?a.x_1<b.x_1:a.y<b.y;});
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(j<=m&&seg[j].y==seg[i].y){
			j++;
		}
		j--;
		if(seg[i].x_1>1){
			continue;
		}
		int max_val=1;
		for(int k=i;k<=j;k++){
			if(seg[k].x_1<=max_val){
				max_val=std::max(max_val,seg[k].x_2);
			}
		}
		lis_y[++lis_y_len]=max_val;
	}
	std::sort(lis_y+1,lis_y+1+lis_y_len);
	int ans=n+lis_y_len;
	lis_x[n+1]=Maxv;
	for(int i=1,j=0;i<=n+1;i++){
		while(j+1<=lis_y_len&&lis_y[j+1]<lis_x[i]){
			j++;
		}
		ans=std::min(ans,i-1+lis_y_len-j);
	}
	printf("%d\n",ans);
	return 0;
}