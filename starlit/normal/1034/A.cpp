#include<bits/stdc++.h>
#define N 300005
#define V 15000007
using namespace std;
int n,a[N],p[V>>3],le[V],b[V],t,d,x,y,ans;
bool np[V];
inline int gcd(int x,int y){
	for(;y;)swap(x,y),y%=x;
	return x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",a+i),d=i>1?gcd(d,a[i]):a[i];
	for(int i=2;i<V;i++){
		if(!np[i])p[t++]=i,le[i]=i;
		for(int j=0;j<t&&i*p[j]<V;j++){
			le[i*p[j]]=p[j];
			np[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=n;i++){
		a[i]/=d;
		for(x=a[i];le[x];){
			b[le[x]]++,y=le[x];
			for(;x%y==0;x/=y);
		}
	}
	for(int i=2;i<V;i++)
	ans=max(ans,b[i]);
	printf("%d",ans?n-ans:-1);
}