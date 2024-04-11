#include<bits/stdc++.h>
using namespace std;
int n,m,k,d1,d2;
long long x,y;
int gcd(int a,int b){
	for(;b;)
	swap(a,b),b%=a;
	return a;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    d1=gcd(n*2,k),d2=gcd(m*2,k);
    x=n*2/d1,y=d1*1ll*m/k;
    if(x>n||d1*1ll*m%k){
		y=m*2/d2,x=d2*1ll*n/k;
		if(y>m||d2*1ll*n%k)return puts("NO"),0;
    }
    printf("YES\n0 0\n%I64d 0\n0 %I64d",x,y);
}