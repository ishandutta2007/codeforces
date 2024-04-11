#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N=5002;
int n,m;
int t[N],l[N],r[N],d[N];
int a[N],mn[N],b[N];

int main(){

    for(int i=0;i<N;i++) mn[i]=1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&t[i],&l[i],&r[i],&d[i]);
        if(t[i]==1){
            for(int j=l[i];j<=r[i];j++) {
                a[j] += d[i];
            }
        } else {
            for(int j=l[i];j<=r[i];j++) {
                mn[j] = min(mn[j], d[i]-a[j]);
                //printf("mn[%d]=%d\n", j,mn[j]);
            }
        }
    }
    for(int i=1;i<=n;i++) b[i]=mn[i];
    for(int i=1;i<=m;i++){  
        if(t[i]==1) {
            for(int j=l[i];j<=r[i];j++) {
                mn[j] += d[i];
            }
        } else {
            int mx = -1e9;
            for(int j=l[i];j<=r[i];j++) {
                mx = max(mx, mn[j]);
            }
            if (mx != d[i]) return !printf("NO\n");
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ", b[i]);
}