#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN  300005
int a[MN],n,m;
LL sum[MN],ans[MN];
struct data{
	int t,k,id;
	bool friend operator<(data a,data b){
		return a.k<b.k;
	}
}w[MN];
void update(int i){
	for(int j=1;j<=n;++j){
		if(j>i)sum[j]=sum[j-i]+a[j];
			else sum[j]=a[j];
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	int Sq=sqrt(n);
	m=read();
	for(int i=1;i<=m;++i){
		w[i].t=read();
		w[i].k=read();
		w[i].id=i;
	}
	sort(w+1,w+1+m);
	int now=0;
	for(int i=1;i<=m;++i){	
		if(w[i].k<=Sq){
			if(w[i].k!=now) update(w[i].k),now=w[i].k;
			ans[w[i].id]=sum[w[i].t+(n-w[i].t)/w[i].k*w[i].k]-sum[w[i].t]+(LL)a[w[i].t];
//			cout<<"HI "<<w[i].t<<" "<<w[i].k<<" "<<ans[w[i].id]<<endl;
		}
		else{
			LL res=0;
			for(;w[i].t<=n;w[i].t+=w[i].k)res+=a[w[i].t];
			ans[w[i].id]=res;
		}
	}
	for(int i=1;i<=m;++i)printf("%I64d\n",ans[i]);
	return 0;
}