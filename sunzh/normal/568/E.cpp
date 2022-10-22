#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
const int inf=0x3f3f3f15;
int n,m;
int a[100010],b[100010],ans[100010];
int f[100010],g[100010];
int l[100010],p[100010];
bool used[100010];
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[++n]=inf;
	m=read();
	for(int i=1;i<=m;++i) b[i]=read();
	sort(b+1,b+m+1);
	memset(f,0x3f,sizeof(f)); 
	for(int i=1;i<=n;++i){
		if(~a[i]){
			int j=lower_bound(f+1,f+n+1,a[i])-f-1;
			l[i]=j+1,p[i]=g[j];f[j+1]=a[i],g[j+1]=i;
//			printf("i:%d,l:%d,p:%d,j:%d\n",i,l[i],p[i],j);
		}
		else{
			for(int j=m,ps=n;j;--j){
				while(ps>0&&f[ps]>=b[j]) --ps;
				if(p==0) break ;
				f[ps+1]=b[j],g[ps+1]=i;
//				printf("i:%d,j:%d,bj:%d,p:%d,fp:%d\n",i,j,b[j],p,f[p]);
			}
		}
	}
	for(int len=l[n],pos=n;len;--len){
//		printf("len:%d,pos:%d\n",len,pos);
		int t;
		if(~a[pos]){
			t=a[pos];
			pos=p[pos];
			if(~a[pos]) ;
			else {
				int j=lower_bound(b+1,b+m+1,t)-b-1;
				used[j]=1,ans[pos]=b[j];
			}
		}
		else{
			t=ans[pos];
			bool flag=0;
			for(int k=pos-1;k;--k){
				if(~a[k]&&a[k]<t&&l[k]==len-1){
					pos=k;flag=1;break ;
				}
			}
			if(flag) continue ;
			for(int k=pos-1;k;--k){
				if(!(~a[k])){
					int j=lower_bound(b+1,b+m+1,t)-b-1;
					used[j]=1;ans[k]=b[j];pos=k;break ;
				}
			}
		}
	}
	int it=1;
	for(int i=1;i<n;++i){
		if(~a[i]) ans[i]=a[i];
		else{
			if(ans[i]) continue ;
			while(used[it]) ++it;
			used[it]=1;ans[i]=b[it];
		}
	}
	for(int i=1;i<n;++i )printf("%d ",ans[i]);
	return 0;
}