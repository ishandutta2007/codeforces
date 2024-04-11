#include <cmath>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=100000;
const int Maxv=100000;
int n;
struct Node{
	int x,y;
	Node(int _x=0,int _y=0){
		x=_x,y=_y;
	}
	friend Node operator +(Node a,Node b){
		return Node(a.x+b.x,a.y+b.y);
	}
	friend Node operator -(Node a,Node b){
		return Node(a.x-b.x,a.y-b.y);
	}
	friend ll operator /(Node a,Node b){
		return 1ll*a.x*b.y-1ll*a.y*b.x;
	}
	ll find_len(){
		return 1ll*x*x+1ll*y*y;
	}
}a[Maxn*6+5];
Node S;
bool cmp_1_less(Node a,Node b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool cmp_1_equal(Node a,Node b){
	return a.x==b.x&&a.y==b.y;
}
bool cmp_2(Node a,Node b){
	if((a-S)/(b-S)==0){
		return (a-S).find_len()<(b-S).find_len();
	}
	return (a-S)/(b-S)>0;
}
int len;
int st[Maxn*6+5],st_top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if(x<v){
			a[++len]=Node(0,std::max(y-v+x,0));
			a[++len]=Node(0,std::min(y+v-x,Maxv));
		}
		else{
			a[++len]=Node(x-v,y);
		}
		if(x+v>Maxv){
			a[++len]=Node(Maxv,std::max(y-v+(Maxv-x),0));
			a[++len]=Node(Maxv,std::min(y+v-(Maxv-x),Maxv));
		}
		else{
			a[++len]=Node(x+v,y);
		}
		if(y<v){
			a[++len]=Node(std::max(x-v+y,0),0);
			a[++len]=Node(std::min(x+v-y,Maxv),0);
		}
		else{
			a[++len]=Node(x,y-v);
		}
		if(y+v>Maxv){
			a[++len]=Node(std::max(x-v+(Maxv-y),0),Maxv);
			a[++len]=Node(std::min(x+v-(Maxv-y),Maxv),Maxv);
		}
		else{
			a[++len]=Node(x,y+v);
		}
	}
	
	std::sort(a+1,a+1+len,cmp_1_less);
	len=std::unique(a+1,a+1+len,cmp_1_equal)-a-1;
	S=a[1];
	std::sort(a+2,a+1+len,cmp_2);
	st[++st_top]=1;
	for(int i=2;i<=len;i++){
		while(st_top>1&&(a[i]-a[st[st_top]])/(a[st[st_top]]-a[st[st_top-1]])>=0){
			st_top--;
		}
		st[++st_top]=i;
	}
	st[0]=st[st_top],st[st_top+1]=st[1];
	int pos=-1;
	double ans=0;
	for(int i=1;i<=st_top;i++){
		Node e_a=a[st[i]]-a[st[i-1]],e_b=a[st[i+1]]-a[st[i]],e_c=a[st[i+1]]-a[st[i-1]];
		double tmp=sqrt(e_a.find_len())*sqrt(e_b.find_len())*sqrt(e_c.find_len())/(std::abs(e_a/e_b));
		if(tmp>ans){
			pos=i;
			ans=tmp;
		}
	}
	printf("%d %d\n",a[st[pos-1]].x,a[st[pos-1]].y);
	printf("%d %d\n",a[st[pos]].x,a[st[pos]].y);
	printf("%d %d\n",a[st[pos+1]].x,a[st[pos+1]].y);
	return 0;
}