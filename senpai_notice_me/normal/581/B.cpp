#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100005

int n,h[MAX_N],suf[MAX_N];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",h+i);
    for (int i=n-1;i>=1;i--) {
        suf[i]=max(suf[i+1],h[i+1]);
    }
    for (int i=1;i<=n;i++) {
        printf("%d ",max(suf[i]-h[i]+1,0));
    }
    
    return 0;
}