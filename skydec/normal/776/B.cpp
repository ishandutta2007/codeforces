#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int pr[N],n;
int main(){
    scanf("%d",&n);
    ++n;
    if(n<=2){
        puts("1");
        puts("1");
        return 0;
    }
    if(n<=3){
        puts("1");
        puts("1 1");
        return 0;
    }
    rep(i,2,n)rep(j,2,n/i)pr[i*j]=1;
    puts("2");
    rep(i,2,n)printf("%d ",pr[i]+1);
    return 0;
}