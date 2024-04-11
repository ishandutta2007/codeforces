#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;
LL x[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        LL a=0,b=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            a+=x[i];
            b^=x[i];
        }
        vector<LL> res; res.push_back(b); a+=b;
        res.push_back(a);
        printf("2\n");
        for(int i=0;i<res.size();i++){
            printf("%lld ", res[i]); 
        }
        printf("\n");
    }   
}
/*
sum = a
xor = b

2 * x = x + a + b  
*/