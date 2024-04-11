#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define max_N 200005

int n,a[max_N],bit[max_N],l[max_N],r[max_N],st[max_N],top;

inline void modify(int x,int y){
	for(x=n-x+1;x<=n;x+=x&-x)bit[x]=max(bit[x],y);
}

inline int query(int x){
	int res=0;
	for(x=n-x+1;x;x-=x&-x)res=max(res,bit[x]);
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	st[top=0]=0;
	for(int i=1;i<=n;++i){
		while(top&&a[st[top]]>=a[i])--top;
		l[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	for(int i=n;i;--i){
		while(top&&a[st[top]]>=a[i])--top;
		r[i]=st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i)modify(r[i]-l[i]+1,a[i]);
	for(int i=1;i<=n;++i)printf("%d ",query(i));
	return puts(""),0;
}