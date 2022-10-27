#include <iostream>
using namespace std;
const int N = 1002;
int n,s;
int a[N],b[N];

int main() {
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
    }

    if(a[1]==0) return !printf("NO\n");
    if(a[s]==1) return !printf("YES\n");

    for(int i=s+1;i<=n;i++) {
        if(a[i]==1 && b[i]==1 && b[s]==1) return !printf("YES\n");
    }
    return !printf("NO\n");
}