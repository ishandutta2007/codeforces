#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 100000 + 10;
int b,k;
int a[N];

int main() {
    scanf("%d%d",&b,&k);
    int ans=0;
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        int x;
        if(b%2==1) {
            x=1;
        } else {
            x=(i==k)?1:0;
        }
        ans = ans + (a[i]%2) * x;
        ans = ans % 2;
    }
    printf("%s\n", ans % 2 == 0 ? "even" : "odd");
}