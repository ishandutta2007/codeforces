#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   1000005
#define P   1000000007
#define For(i,a,b)  for(int i=a;i<=b;i++)

int     N,A[n];

int     Num(int x){
        int ret=1;
        For(i,2,x)  ret=1ll*ret*i%P;
        return  ret;
}
int     Pow(int a,int b){
        int ret=1;
        for (;b;b>>=1,a=1ll*a*a%P)
            if  (b&1)   ret=1ll*ret*a%P;
        return  ret;
}

int     main(){
        scanf("%d",&N); N++;
        printf("%d\n",(2ll*Num(2*N-1)*Pow(1ll*Num(N)*Num(N-1)%P,P-2)%P+P-1)%P);
}