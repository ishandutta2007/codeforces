#include<bits/stdc++.h>
#define maxn 1010

using namespace std;
bool a[maxn][maxn];
int n,p,q,m;

int main(){
    cin >> n >> p >> q;
    if (p>1&&q>1) {
        puts("NO");
        return 0;
    }
    if (n<=3&&n>=2&&p==1&&q==1) {
        puts("NO");
        return 0;
    }
    puts("YES");
    if (p==1&&q==1){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) printf("%d",abs(i-j)==1); printf("\n");
        }
        return 0;
    }
    if (p==1){
        memset(a,1,sizeof(a));
        m=n-q;
        for (int i=2;i<=m+1;i++) a[1][i]=a[i][1]=0;
        for (int i=1;i<=n;i++) a[i][i]=0;
    }
    else {
        m=n-p;
        for (int i=2;i<=m+1;i++) a[1][i]=a[i][1]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d",a[i][j]); printf("\n");
    }
}