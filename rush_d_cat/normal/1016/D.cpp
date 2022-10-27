#include <iostream>
#include<vector>
using namespace std;
const int N=102;
int has[100][102][102];
int n,m,a[N],b[N];
int r[N],c[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int k=0;k<32;k++) {
        vector<int> r,c;
        for(int i=1;i<=n;i++) if((a[i]>>k)&1) r.push_back(i);
        for(int i=1;i<=m;i++) if((b[i]>>k)&1) c.push_back(i);
        if(r.size()%2 != c.size()%2) return !printf("NO\n");
        for(int i=0;i<min(r.size(),c.size());i++) has[k][r[i]][c[i]]=1;
    
        if(r.size()<c.size()) {
            for(int i=r.size();i<c.size();i++) if(has[k][1][c[i]]==0) {
                has[k][1][c[i]]=1;
            }
        } else {
            for(int i=c.size();i<r.size();i++) if(has[k][r[i]][1]==0) {
                has[k][r[i]][1]=1;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans=0;
            for(int k=0;k<32;k++) if(has[k][i][j]) ans |= (1LL<<k);
            printf("%d ", ans);
        }
        printf("\n");
    }
}