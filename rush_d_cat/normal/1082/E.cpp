#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 500000 + 10;
const int INF = 1e9+7;

int n,c;
int a[N],s[N],f[N],cnt[N];
int mx[N];

int main(){
    scanf("%d%d",&n,&c);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==c)ans++,tot++;
    }
    for(int i=0;i<N;i++)mx[i]=-INF;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(a[i]==c) f[i]++;
        cnt[a[i]] ++;
    }


    for(int i=n;i>=0;i--){
        if(i<n)ans = max(ans, mx[a[i+1]] - (cnt[a[i+1]]-f[i]) + tot);
        mx[a[i]] = max(mx[a[i]], cnt[a[i]] - f[i]); cnt[a[i]] --;
    }
    printf("%d\n", ans);
}