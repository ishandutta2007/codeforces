#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double ld;
const int Maxn=10000;
const ld PI=acosl(-1.0L),eps=1e-10;
int n,m;
struct Node{
	int x,y;
	Node(int _x=0,int _y=0){
		x=_x;
		y=_y;
	}
	friend bool operator <(Node a,Node b){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.x;
	}
	friend Node operator +(Node a,Node b){
		Node ans;
		ans.x=a.x+b.x;
		ans.y=a.y+b.y;
		return ans;
	}
	friend Node operator -(Node a,Node b){
		Node ans;
		ans.x=a.x-b.x;
		ans.y=a.y-b.y;
		return ans;
	}
	friend int operator *(Node a,Node b){
		return a.x*b.x+a.y*b.y;
	}
	friend int operator %(Node a,Node b){
		return a.x*b.y-a.y*b.x;
	}
}a[Maxn+5],b[Maxn+5],c[Maxn+5];
int c_len;
bool check(Node x,Node y){
	ld l=-1e100L,r=1e100L;
	for(int i=1;i<=n;i++){
		Node now=a[i];
		if((x-now)%(y-now)==0){
			continue;
		}
		ld w=1.0L*((x-now)*(y-now))/((x-now)%(y-now));
		if((now-x)%(y-x)<0){
			l=max(l,w);
		}
		else{
			r=min(r,w);
		}
	}
	for(int i=1;i<=m;i++){
		Node now=b[i];
		if((x-now)%(y-now)==0){
			if(now.x>=min(x.x,y.x)&&now.x<=max(x.x,y.x)&&now.y>=min(x.y,y.y)&&now.y<=max(x.y,y.y)){
				return 0;
			}
			continue;
		}
		ld w=1.0L*((x-now)*(y-now))/((x-now)%(y-now));
		if((now-x)%(y-x)>0){
			l=max(l,w);
		}
		else{
			r=min(r,w);
		}
	}
	return l+eps<r;
}
bool dfs(int l,int r){
	if(l+1==r){
		return 0;
	}
	int x;
	ld k=1e100L;
	for(int i=l+1;i<r;i++){
		Node now=c[i];
		ld w=1.0L*((now-c[l])*(now-c[r]))/((now-c[l])%(now-c[r]));
		if(w<k){
			x=i;
			k=w;
		}
	}
	return check(c[l],c[x])||check(c[r],c[x])||dfs(l,x)||dfs(x,r);
}
bool work(){
	c_len=0;
	for(int i=1;i<=n;i++){
		while(c_len>1&&(c[c_len]-c[c_len-1])%(a[i]-c[c_len-1])<=0){
			c_len--;
		}
		c[++c_len]=a[i];
	}
	int tmp=c_len;
	for(int i=n-1;i>0;i--){
		while(c_len>tmp&&(c[c_len]-c[c_len-1])%(a[i]-c[c_len-1])<=0){
			c_len--;
		}
		c[++c_len]=a[i];
	}
	c_len--;
	return check(c[1],c[c_len])||dfs(1,c_len);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	if(n==1||m==1){
		puts("YES");
		return 0;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(work()){
		puts("YES");
		return 0;
	}
	swap(n,m);
	swap(a,b);
	if(work()){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}