#include <iostream>
using namespace std;
const int N=3000000+10;
int n,t;
int a[N],vis[N];

int main() {
    scanf("%d%d",&n,&t);
    for(int i=1;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int now=1;
    while(now<n) {
        vis[now]=1; vis[now+a[now]]=1;
        now=now+a[now];
    }
    printf("%s\n", vis[t]?"YES":"NO");
}