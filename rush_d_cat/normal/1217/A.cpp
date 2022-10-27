#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T;
int main() {
    scanf("%d", &T);
    while(T--) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        // a+? > b+c-?
        int low=(b+c-a)/2 + 1; if(b+c-a<0) low=0;
        printf("%d\n", max(0, c-low+1));
    }
}