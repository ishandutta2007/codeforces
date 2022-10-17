#include <cmath>
#include <cstdio>
#define ll long long
#define Maxn 100000
long double f[Maxn+5];
long double C(int n,int m) {
	return f[n]-f[m]-f[n-m];
}
template<typename Elem_1,typename Elem_2>
Elem_1 mn(Elem_1 a,Elem_2 b){
	return a<b?a:b;
}
int main(){
	f[0]=0;
	for(int i=1;i<=Maxn;i++){
		f[i]=f[i-1]+log(1.0*i);
	}
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	long double ans=0.0;
	long double tmp;
	for(int x=0;x<=n;x++){
		for(int y=0,z;y<=n;y++){
			if(n*(x+y)-x*y<=k){
				z=n*(x+y)-x*y;
				tmp=C(n,x)+C(n,y)+C(m-z,k-z)-C(m,k);
				ans=mn(1e99,ans+exp(tmp));
			}
		}
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}