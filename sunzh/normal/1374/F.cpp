#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
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
int T;
int n;
int a[510];
int pos[510];
struct node{
	int val,id;
}b[510];
bool cmp(node x,node y){
	return x.val==y.val?x.id<y.id:x.val<y.val;
}
int m; 
int ans[250010];
map<int,int>vis;
int main(){
//	freopen("test.in","r",stdin);
	T=read();
	while(T--){
		n=read();m=0;
		for(int i=1;i<=n;++i) a[i]=read(),b[i].val=a[i],b[i].id=i;
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;++i) a[b[i].id]=i;
		for(int i=1;i<=n;++i) pos[a[i]]=i;
		for(int i=1;i<=n-2;++i){
			int p=pos[i];
//			printf("i:%d,p:%d\n",i,p);
			while(p>=i+2){
				pos[a[p-1]]=p,pos[a[p-2]]=p-1;pos[a[p]]=p-2;
				swap(a[p-2],a[p]);swap(a[p-1],a[p]);
//				printf("P:%d,ap:%d,ap-1:%d,ap-2:%d\n",p,a[p],a[p-1],a[p-2]);
				ans[++m]=p-2;p-=2;
			}
			if(p==i+1){
				ans[++m]=i,ans[++m]=i;
				pos[a[p]]=p-1;pos[a[p-1]]=p+1,pos[a[p+1]]=p;
				int t1=a[p-1],t2=a[p+1];a[p-1]=a[p],a[p]=t2,a[p+1]=t1;
			}
		}
//		printf("F");
		if(b[a[n-1]].val>b[a[n]].val){
			vis.clear();
			bool flag=0;
			for(int i=1;i<=n;++i){
				if(!vis.count(b[i].val)){
					vis[b[i].val]=b[i].id;a[b[i].id]=i;
				}
				else{
					a[b[i].id]=i;
					if(!flag) swap(a[vis[b[i].val]],a[b[i].id]);
					flag=1;
					vis.erase(b[i].val);
				}
			}
			for(int i=1;i<=n;++i) pos[a[i]]=i;
			m=0;
			for(int i=1;i<=n-2;++i){
				int p=pos[i];
				while(p>=i+2){
					pos[a[p-1]]=p,pos[a[p-2]]=p-1;pos[a[p]]=p-2;
					swap(a[p-2],a[p]);swap(a[p-1],a[p]);
					ans[++m]=p-2;p-=2;
				}
				if(p==i+1){
					ans[++m]=i,ans[++m]=i;
					pos[a[p]]=p-1;pos[a[p-1]]=p+1,pos[a[p+1]]=p;
					int t1=a[p-1],t2=a[p+1];a[p-1]=a[p],a[p]=t2,a[p+1]=t1;
				}
			}
			if(b[a[n-1]].val>b[a[n]].val){
				printf("-1\n");
			}
			else{
				printf("%d\n",m);
				for(int i=1;i<=m;++i) printf("%d ",ans[i]);
				printf("\n");
			}
		}
		else{
			printf("%d\n",m);
			for(int i=1;i<=m;++i) printf("%d ",ans[i]);
			printf("\n");
		}
	}
}