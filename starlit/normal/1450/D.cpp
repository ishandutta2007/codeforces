#include<bits/stdc++.h>
const int N=300005;
using namespace std;
int T,n,a[N],b[N<<2],l,r;
bool c[N],ans[N];
void ins(int k,int l,int r,int x,int v){
	if(l==r)b[k]=v;
	else{
		int mi=l+r>>1;
		if(x>mi)ins(k<<1|1,mi+1,r,x,v);
		else ins(k<<1,l,mi,x,v);
		b[k]=min(b[k<<1],b[k<<1|1]);
	}
}
int qry(int k,int l,int r,int L,int R){
	if(R<l||L>r)return N;
	if(L<=l&&R>=r)return b[k];
	int mi=l+r>>1;
	return min(qry(k<<1,l,mi,L,R),qry(k<<1|1,mi+1,r,L,R));
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);l=1,r=n;
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;i++)
		scanf("%d",a+i),ins(1,1,n,i,a[i]);
		for(int i=1;i<=n;i++)c[a[i]]=1;
		ans[1]=1;
		for(int i=1;i<=n;i++)
		if(!c[i])ans[1]=0;
		ans[n]=c[1];
		for(int i=n-1;i>1;i--){
			if(!ans[i+1])break;
			int a=qry(1,1,n,l,r-1),b=qry(1,1,n,l+1,r);
			//cerr<<a<<'/'<<b<<endl;
			if(a==n-i&&b==n-i+1)l++;
			else if(a==n-i+1&&b==n-i)r--;
			else break;
			ans[i]=1;
		}
		for(int i=1;i<=n;i++)
		printf("%d",ans[i]);puts("");
	}
}