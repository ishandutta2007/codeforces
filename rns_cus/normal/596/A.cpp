#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void print(int x) {
    if(x<0) x=-x;
    printf("%d\n",x);
    exit(0);
}

void solve(int x,int y,int z,int w) {
    if(x==z) return;
    if(y==w) return;
    print((x-z)*(y-w));
}

int main() {
    ///freopen("1.in","r",stdin);
    int n;
    int x[10],y[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
    if(n==1) return puts("-1");
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            solve(x[i],y[i],x[j],y[j]);
        }
    }
    puts("-1");
}