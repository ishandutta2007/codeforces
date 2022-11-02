#include<bits/stdc++.h>
const int N=100005,inf=2e9;
using namespace std;
int n,m,re,a[N],b[N],c[N],f[N],ans[N],tp,
ss[N],sd[N],t;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),ans[i]=a[i];
	a[++n]=inf-1;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	scanf("%d",b+i);
	sort(b,b+m);
	for(int i=0;i<m;i++)ss[i]=b[m-i-1];
	m=unique(b,b+m)-b;
	for(int i=1;i<=n;i++)c[i]=inf;
	for(int i=1;i<=n;i++)
	if(a[i]>0){
		for(int l=1,r=n,mi;l<=r;)
		if(c[mi=l+r>>1]<a[i])
		l=mi+1;
		else re=mi,r=mi-1;
		f[i]=re,c[re]=a[i];
	}
	else
	for(int j=n,k=m-1;~k;k--){
		for(;c[j]>=b[k];j--);
		c[j+1]=b[k];
	}
	for(int i=n,j=m-1,ti,k;i;){
		//cerr<<"chk "<<i<<'/'<<f[i]<<endl;
		for(;j>=0&&b[j]>=a[i];j--);
		ti=tp=0;
		for(k=i-1;;k--)
		if(a[k]<0)ti++;
		else if((tp=f[i]-f[k])>0){
			if(--tp){
				if(tp<=ti&&a[k]<b[j-tp+1])
				break;
			}else if(a[k]<a[i])break;
		}
		for(;i>k;i--)
		if(a[i]<0&&tp)//cerr<<"ins "<<b[j]<<endl,
		tp--,sd[t++]=b[j],ans[i]=b[j--];
	}t=0;
	for(int i=1,h=0;i<n;i++)
	if(ans[i]<0){
		for(;ss[h]==sd[t];h++,t++)
		//cerr<<"del "<<ss[h]<<endl
		;
		printf("%d ",ss[h++]);
	}else printf("%d ",ans[i]);
}