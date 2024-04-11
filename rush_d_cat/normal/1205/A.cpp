#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++){
        a[i]=2*i-1;
        a[i+n]=2*i;
    }
    for(int i=2;i<=n;i+=2){
        swap(a[i],a[i+n]);
    }
    if(n%2==0) return !printf("NO\n");
    printf("YES\n");
    for(int i=1;i<=n<<1;i++){
        printf("%d ", a[i]);
    }
}