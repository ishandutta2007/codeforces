#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
int a[Maxn+5];
int b[Maxn+5];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n&1){
        puts("NO");
        return;
    }
    std::sort(a+1,a+1+n);
    for(int i=1;i<=n/2;i++){
        b[i*2-1]=a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        b[(i-n/2)*2]=a[i];
    }
    b[0]=b[n],b[n+1]=b[1];
    for(int i=1;i<=n;i++){
        if((b[i]>b[i-1]&&b[i]>b[i+1])||(b[i]<b[i-1]&&b[i]<b[i+1])){
            continue;
        }
        puts("NO");
        return;
    }
    puts("YES");
    for(int i=1;i<=n;i++){
        printf("%d ",b[i]);
    }
    puts("");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}