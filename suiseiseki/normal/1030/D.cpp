#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(k/gcd((ll)n*m,k)>2){
        puts("NO");
        return 0;
    }
    ll now;
    now=((ll)n*m<<1)/k;
    int l=(now+n-1)/n;
    int r=l*n-now;
    puts("YES");
    puts("0 0");
    printf("%d %d\n",r,l);
    printf("%d 1\n",n);
    return 0;
}