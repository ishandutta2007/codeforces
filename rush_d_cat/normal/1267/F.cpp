#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
void print(int p[],int n){
    int vis[n] = {0};
    for(int i=1;i<=n;i++) vis[p[i]]++;
    set<int> s; for(int i=1;i<=n;i++) if(vis[i]==0) s.insert(i);
    for(int i=1;i<=n-2;i++){
        int x = *s.begin(), y = p[i];
        cout<<x<<' '<<y<<endl;
        s.erase(x); vis[y]--;
        if(vis[y]==0) s.insert(y);
    }
    int x = *s.begin(), y = n;
    cout<<x<<' '<<y<<endl;
}
int p[N],a[N],b[N],vis[N];
int main(){
    int n,m,k1,k2; scanf("%d%d%d%d",&n,&m,&k1,&k2);
    for(int i=1;i<=k1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k2;i++) scanf("%d",&b[i]);
    for(int i=1;i<=k1;i++) vis[a[i]]++;
    int x = 0;
    for(int i=1;i<=n;i++) x += (vis[i]!=0);
    int p1 = 1, p2 = 1, top = 0;
    if(n+m-2-(k1+x-1)<n-x) return 0 * printf("No\n");
    for(int i=0;i<n-x;i++){
        if(p2<=k2) p[++top] = b[p2++];
        else p[++top] = n + 1;
    }
    for(int i=0;i<(n+m-2-(k1+x-1))-(n-x);i++){
        p[++top] = a[1];
    }
    for(int i=1;i<=k1;i++){
        p[++top] = a[i];
        vis[a[i]]--;
        if(vis[a[i]]==0&&i!=k1){
            if(p2<=k2) p[++top] = b[p2++];
            else p[++top] = n + 1;
        }
    }
    if(p2<=k2) return 0 * printf("No\n");
    printf("Yes\n");
//    for(int i=1;i<=top;i++) cout<<p[i]<<' '; cout<<endl;
    print(p,n+m);
}