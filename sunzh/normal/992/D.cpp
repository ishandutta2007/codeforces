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
const long long llmax=5e18;
int n,k;
int a[200010];
int nxt[200010];
long long ans;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	nxt[n]=n+1;
	for(int i=n-1;i>=1;--i) nxt[i]=(a[i+1]==1?nxt[i+1]:i+1);
//	for(int i=1;i<=n;++i) printf("%d\n",nxt[i]);
	for(int i=1;i<=n;++i){
		long long sum=a[i];
		long long s=a[i];
		if(k==1) ++ans;
		for(int j=i,l=nxt[i];j<=n;j=nxt[j],l=nxt[j]){
			long long tmp=sum-s*k;
			if(tmp>0&&tmp%k==0&&tmp/k<(l-j)) ++ans;
			if((llmax/sum)<=a[l])  break ;
			s+=a[l]+l-j-1;sum*=a[l];
			if(s*k==sum) ++ans;
//			printf("i:%d,j:%d,l:%d,s:%d,sum:%d\n",i,j,l,s,sum);
		}
	}
	printf("%lld\n",ans);
	return 0;
}