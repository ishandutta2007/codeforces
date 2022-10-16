#include <cstdio>
#include <algorithm>
const int Maxn=132674;
const int Inf=0x3f3f3f3f;
int n;
struct Rectangle{
	int x_l,x_r;
	int y_l,y_r;
}a[Maxn+5];
struct Value_mn{
	int mn_v,nxt_v;
	Value_mn(){
		mn_v=nxt_v=Inf;
	}
	void update(int x){
		if(x<mn_v){
			nxt_v=mn_v;
			mn_v=x;
		}
		else{
			nxt_v=std::min(nxt_v,x);
		}
	}
	int get_val(int x){
		return x==mn_v?nxt_v:mn_v;
	}
}mn_x,mn_y;
struct Value_mx{
	int mx_v,nxt_v;
	Value_mx(){
		mx_v=nxt_v=-Inf;
	}
	void update(int x){
		if(x>mx_v){
			nxt_v=mx_v;
			mx_v=x;
		}
		else{
			nxt_v=std::max(nxt_v,x);
		}
	}
	int get_val(int x){
		return x==mx_v?nxt_v:mx_v;
	}
}mx_x,mx_y;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x_l,&a[i].y_l,&a[i].x_r,&a[i].y_r);
		mn_x.update(a[i].x_r),mx_x.update(a[i].x_l);
		mn_y.update(a[i].y_r),mx_y.update(a[i].y_l);
	}
	for(int i=1;i<=n;i++){
		int x_l=mx_x.get_val(a[i].x_l),x_r=mn_x.get_val(a[i].x_r);
		int y_l=mx_y.get_val(a[i].y_l),y_r=mn_y.get_val(a[i].y_r);
		if(x_l<=x_r&&y_l<=y_r){
			printf("%d %d\n",x_l,y_l);
			break;
		}
	}
	return 0;
}