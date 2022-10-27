#include <iostream>

using namespace std;
const int N=100002;
int n,c[N],a[N];
int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]), c[a[i]]++;
    for(int i=1;i<=5000;i++) c[i]+=c[i-1];
    int ans=N,x=0;
    for(int low=1;low<=5000;low++){
        ans=min(ans, x + c[5000] - c[min(2*low, 5000)]);
        x += c[low]-c[low-1];
    }
    printf("%d\n", ans);
}