#include <iostream>
using namespace std;
#define L int64_t
#define R return
L M=1e9+7,F[1<<20],x,y,g;
L P(L a,L b){R (!b?1:(b&1?a*P(a*a%M,b/2)%M:P(a*a%M,b/2)%M));}
L C(L k,L n){
	if(n==k||k==0)R 1;
	R F[n]*P(F[k],M-2)%M*P(F[n-k],M-2)%M;
}
L f(L x){
	if (x==0&&y==1)R 1;
	if ((x==0&&y>1)||(x==1&&y==0))R 0;
	R (C(y,x+y-1)-f(x-1)+M)%M;
}
int main(){
	F[0]=1;
	for(L i=1;i<1e6;i++)F[i]=F[i-1]*i%M;	
	cin>>x>>y>>g;
	if(g)cout<<f(x);
	else cout<<(C(x,x+y)-f(x)+M)%M;
}