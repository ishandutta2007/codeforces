#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 400000
int f[Maxn+5];
int g[Maxn+5];
int a[Maxn+5];
int d[Maxn+5];
bool must[Maxn+5];
int n,m;
int mx(int a,int b){
	return a>b?a:b;
}
int x[Maxn<<1|5];
struct Question{
	int a,b;
	int id;
	int ans;
	friend bool operator <(Question p,Question q){
		return p.a<q.a;
	}
}q[Maxn+5];;
bool cmp(Question p,Question q){
	return p.id<q.id;
}
int b[Maxn<<1|5];
int cnt;
void add(int x,int a){
	for(int i=x;i<=cnt;i+=(i&(-i))){
		b[i]=mx(b[i],a);
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans=mx(ans,b[i]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	int len=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x[++cnt]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].a,&q[i].b);
		q[i].id=i;
		q[i].ans=0;
		x[++cnt]=q[i].b;
	}
	sort(x+1,x+1+cnt);
	int *end=unique(x+1,x+1+cnt);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(x+1,end,a[i])-x;
	}
	for(int i=1;i<=m;i++){
		q[i].b=lower_bound(x+1,end,q[i].b)-x;
	}
	sort(q+1,q+1+m);
	len=0;
	int left,right,mid;
	for(int i=1;i<=n;i++){
		if(a[i]>d[len]){
			d[++len]=a[i];
			f[i]=len;
			continue;
		}
		left=0,right=len;
		while(left<right){
			mid=(left+right+1)>>1;
			if(d[mid]>=a[i]){
				right=mid-1;
			}
			else{
				left=mid;
			}
		}
		if(a[i]<d[left+1]){
			d[left+1]=a[i];
		}
		f[i]=left+1;
	}
	len=0;
	d[0]=(1<<30);
	for(int i=n;i>0;i--){
		if(a[i]<d[len]){
			d[++len]=a[i];
			g[i]=len;
			continue;
		}
		left=0,right=len;
		while(left<right){
			mid=(left+right+1)>>1;
			if(d[mid]<=a[i]){
				right=mid-1;
			}
			else{
				left=mid;
			}
		}
		if(a[i]>d[left+1]){
			d[left+1]=a[i];
		}
		g[i]=left+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=mx(ans,f[i]);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(f[i]+g[i]-1==ans){
			must[i]=1;
			if(a[i]<=maxn){
				must[i]=0;
			}
			else{
				maxn=a[i];
			}
		}
	}
	int minn=(1<<30);
	for(int i=n;i>0;i--){
		if(f[i]+g[i]-1==ans){
			if(a[i]>=minn){
				must[i]=0;
			}
			else{
				minn=a[i];
			}
		}
	}
	for(int i=1,j=1;i<=n&&j<=m;i++){
		for(;j<=m&&q[j].a==i;j++){
			q[j].ans+=query(q[j].b-1);
		}
		add(a[i],f[i]);
	}
	memset(b,0,sizeof b);
	for(int i=n,j=m;i>0&&j>0;i--){
		for(;j>0&&q[j].a==i;j--){
			q[j].ans+=query(cnt-q[j].b);
		}
		add(cnt-a[i]+1,g[i]);
	}
	for(int i=1;i<=m;i++){
		q[i].ans++;
		if(!must[q[i].a]){
			q[i].ans=mx(q[i].ans,ans);
		}
		else{
			q[i].ans=mx(q[i].ans,ans-1);
		}
	}
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++){
		printf("%d\n",q[i].ans);
	}
	return 0;
}