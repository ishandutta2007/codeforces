#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
int t;
int n,x,y,d;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&y,&d);
        int ans = 1e9+7;
        if(abs(x-y)%d==0)ans=abs(x-y)/d;
        if((y-1)%d==0){
            ans = min(ans, (x-1+d-1)/d + (y-1)/d);
        }
        if((n-y)%d==0){
            ans = min(ans, (n-x+d-1)/d + (n-y)/d);
        }
        if(ans==1e9+7)ans=-1;
        printf("%d\n", ans);
    }
}