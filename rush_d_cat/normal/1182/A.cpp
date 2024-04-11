#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long LL;

const int N=10000+10;
int n;
int main() {
    cin >> n;
    int ans = 1;
    if (n % 2 == 1) printf("0\n");
    else {
        for(int i=1;i<=n/2;i++) ans<<=1;
        printf("%d\n", ans);
    }
}