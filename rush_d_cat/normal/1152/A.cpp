#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m;
int c[2][2];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x); c[0][x%2]++;
    }
    for(int i=1;i<=m;i++){
        int x; scanf("%d",&x); c[1][x%2]++;
    }
    int ans=min(c[0][0],c[1][1])+min(c[0][1],c[1][0]);
    cout<<ans<<endl;
}