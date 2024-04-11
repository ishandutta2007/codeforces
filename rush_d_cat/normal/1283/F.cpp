#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N],u[N],v[N],par[N],vis[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) scanf("%d",&a[i]);
    int rt=a[1],mx=n;
    if(a[1]==mx) --mx; 
    par[a[1]]=a[1]; 
    vis[a[1]]=1;
    for(int i=2;i<=n;i++){
        if(vis[a[i]]==1) {
            u[i-1]=a[i-1], v[i-1]=mx; 
            --mx;
        } else {
            u[i-1]=a[i-1], v[i-1]=a[i]; 
            if(v[i-1]==mx) --mx;
        }
        vis[u[i-1]]=1; vis[v[i-1]]=1;
        while(vis[mx])--mx;
    }
    v[n-1]=mx;
    printf("%d\n", a[1]);
    for(int i=1;i<n;i++)printf("%d %d\n", u[i],v[i]);
}
/*
3
6
*/