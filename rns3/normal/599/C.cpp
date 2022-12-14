#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define M 200001

int h[M];
int n;
int mi[M];


int main() {
    ///freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    mi[n+1] = h[n];
    for(int i=n;i;i--) mi[i] = min(mi[i+1],h[i]);
    int i = 1;
    int ans = 0;
    for(;i<=n;) {
        int j=i,tp = 0;
        for(;j<=n;j++) {
            tp = max(tp,h[j]);
            if(tp<=mi[j+1]) break;
        }
        ///printf("%d %d\n",i,j);
        i=j+1;
        ans++;
    }
    printf("%d\n",ans);
}