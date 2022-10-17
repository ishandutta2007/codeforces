#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 41
struct Node{
	int x,y;
	friend bool operator <(Node p,Node q){
		if(p.x==q.x){
			return p.y<q.y;
		}
		return p.x<q.x;
	}
}a[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
void swp(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int n,m;
bool cmp(Node p,Node q){
	if(p.y==q.y){
		return p.x<q.x;
	}
	return p.y<q.y;
}
int x[Maxn+5],y[Maxn+5];
bool check(){
	int mn_x=55,mn_y=55,mx_x=-1,mx_y=-1;
	for(int i=1;i<m;i++){
		mn_x=mn(mn_x,x[i]);
		mn_y=mn(mn_y,y[i]);
		mx_x=mx(mx_x,x[i]);
		mx_y=mx(mx_y,y[i]);
	}
	if(mx_x-mn_x!=mx_y-mn_y){
		return 0;
	}
	for(int i=1;i<m;i++){
		if(x[i]!=mn_x&&x[i]!=mx_x&&y[i]!=mn_y&&y[i]!=mx_y){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	m=(n<<2)+1;
	for(int i=1;i<=(n<<2)+1;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+(n<<2)+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				continue;
			}
			if(j>i){
				x[j-1]=a[j].x;
				y[j-1]=a[j].y;
			}
			else{
				x[j]=a[j].x;
				y[j]=a[j].y;
			}
		}
		if(check()){
			printf("%d %d\n",a[i].x,a[i].y);
			break;
		}
	}
	return 0;
}