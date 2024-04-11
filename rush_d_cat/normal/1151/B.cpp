#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N=500+10;
int n,m,a[N][N];
set<int> st[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            st[i].insert(a[i][j]);
        }
    }
    bool ok=0;
    for(int i=1;i<=n;i++){
        if(st[i].size()>1) ok=1;
    }
    if(ok==0) {
        int ans=0;
        for(int i=1;i<=n;i++){
            ans^=a[i][1];
        }
        if(ans==0) {
            return !printf("NIE\n");
        }
        printf("TAK\n");
        for(int i=1;i<=n;i++){
            printf("1 ");
        }
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans^=a[i][1];
    }
    printf("TAK\n");
    if (ans) {
        for(int i=1;i<=n;i++){
            printf("1 ");
        }
    } else {
        int pos=0;
        for(int i=1;i<=n;i++){
            if(st[i].size()>1) {
                pos=i;
                break;
            }
        }
        int to=-1;
        for(int i=1;i<=m;i++){
            if(a[pos][i]!=a[pos][1]){
                to=i; break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=pos)
            printf("1 ");
            else
            printf("%d ", to);
        }
    }
    return 0;
}