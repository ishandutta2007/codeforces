#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N=200000+10;
int n,a[N],c[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); c[a[i]]++;
    }
    for(int i=1;;i++){
        if(c[i]>=1 && c[i]<=n/2) {
            printf("Alice\n"); return 0;
        } else if(c[i]>n/2) {
            printf("Bob\n"); return 0;
        }
    }
}