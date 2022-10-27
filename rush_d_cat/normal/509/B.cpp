#include <iostream>
#include <vector>
using namespace std;
int n,k;
int a[102];
vector<int> v[102];
int main(){
    scanf("%d%d",&n,&k);

    int mn=102,mx=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    if(mx-mn>k) return !printf("NO\n");

    for(int i=1;i<=k;i++) {
        int mx=0;
        for(int j=1;j<=n;j++) {
            mx = max(mx, a[j]);
        }
        if(mx==0) break;
    
        for(int j=1;j<=n;j++) {
            if(a[j]==mx) {
                a[j]--; v[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=a[i];j++){
            v[i].push_back(k);
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) {
        for(auto x: v[i]) printf("%d ", x); printf("\n");
    }
}