#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 200000
struct Node{
	ll a;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.a==q.a){
			return p.id<q.id;
		}
		return p.a<q.a;
	}
}a[Maxn+5],b[Maxn*3+5];
int m,n;
int c[Maxn+5];
ll f[Maxn*3+5];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].a);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i].a);
		b[i].id=i;
		b[i+n]=b[i];
		b[i+n].a+=m;
		b[i+(n<<1)]=b[i];
		b[i+(n<<1)].a-=m;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n*3);
	ll ans=(1ll<<60),sum;
	int x=0;
	for(int i=1,j=1;i<=n;i++){
		while(b[j].a<=a[i].a){
			j++;
		}
		f[0]+=a[i].a;
		if(j-i+1<=2*n+1){
			f[j-i+1]-=(a[i].a<<1);
		}
	}
	for(int j=1,i=1;j<=n*3;j++){
		f[mx(0,j-n+1)]-=b[j].a;
		while(i<=n&&a[i].a<b[j].a){
			i++;
		}
		if(j-i+2<=n*2+1){
			f[j-i+2]+=(b[j].a<<1);
		}
		f[mn(n*2+2,j+1)]-=b[j].a;
	}
	sum=f[0];
	for(int i=1;i<=2*n+1;i++){
		sum+=f[i];
		if(sum<ans){
			x=i;
			ans=sum;
		}
	}
	for(int i=1;i<=n;i++){
		c[a[i].id]=b[x+i-1].id;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		printf("%d ",c[i]);
	}
	puts("");
	return 0;
}