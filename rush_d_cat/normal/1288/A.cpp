#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=1002;
const LL MOD=1e9+7;
int t,n,d;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        int x=sqrt(d);
        int B=1000000;
        int mn=1e9+7;
        for(int i=max(x-B,0);i<=x+B;i++){
            mn=min(mn,i+(d+i)/(i+1));
        }
        printf("%s\n", mn<=n?"YES":"NO");
    }
}