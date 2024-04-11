#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int m,n;
struct node{
	int val,id;
	bool operator <(const node &x)const {
		return val<x.val;
	}
}a[200010],b[600010];
int c[400010];
int ans[200010];
void add(int l,int r,int k){
//	printf("l:%d,r:%d,k:%d\n",l,r,k);
//	if(l==0) return ;
//if(l>r) return ;
	c[l]+=k,c[r+1]-=k;
}
int mon(int x){
	while(x>n) x-=n;
	return x;
}
signed main(){
	m=read(),n=read();
	for(int i=1;i<=n;++i) a[i].val=read(),a[i].id=i;
	for(int i=1;i<=n;++i) b[i].val=read(),b[i].id=i;
	sort(a+1,a+n+1);sort(b+1,b+n+1);
//	for(int i=1;i<=n;++i) printf("%d %d\n",b[i].id,b[i].val);
	for(int i=1;i<=n;++i) a[i].val+=m;
	for(int i=1;i<=n+n;++i) b[i+n]=b[i],b[i+n].val+=m;
	for(int i=1;i<=n;++i) c[0]+=a[i].val;//-b[i].val;
	for(int i=1;i<=n;++i){
		int j=upper_bound(b+1,b+3*n+1,a[i])-b;
//		printf("%d ,%d ,%d\n",a[i].val,b[j].val,j);
		if(j>i&&j<=i+2*n) c[j-i]-=2*a[i].val;
	}
	for(int i=1;i<=3*n;++i){
		if(i<=n){
			add(0,i-1,-b[i].val);continue ;
		}
		if(i>(n<<1)){
			add(i-n,n<<1,b[i].val);continue ;
		}
		int j=lower_bound(a+1,a+n+1,b[i])-a;
		add(i-j+1,i-1,b[i].val);add(i-n,i-j,-b[i].val);
	}
	int ansid=0;
	for(int i=1;i<=(n<<1);++i){
//		printf("i:%d,c:%d\n",i,c[i]);
		c[i]+=c[i-1];
		if(c[i]<c[ansid]){
			ansid=i;
		}
	}
//	printf("%d\n",c[0]);
	printf("%lld\n",c[ansid]);
	for(int i=1;i<=n;++i) ans[a[i].id]=b[mon(i+ansid)].id;
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}