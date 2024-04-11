#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=200000+10;
typedef long long LL;
int t;
int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        LL x;scanf("%lld",&x);
        if(x>=14 && x%14>=1 && x%14<=6) printf("YES\n");
        else printf("NO\n");
    }
}