#include <iostream>
using namespace std;
typedef long long LL;
const int N=1002;
const LL MOD=1e9+7;
int t,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        int c=0; LL x=9;
        while(x<=b){
            c++; x=x*10+9;
        }
        printf("%lld\n", (LL)a*c);
    }
}