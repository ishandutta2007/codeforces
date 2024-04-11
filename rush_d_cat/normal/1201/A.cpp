#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2000 + 10;
int n,m,a[N];
char s[N][N];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int j=1;j<=m;j++){
        int c[6]={0};
        for(int i=1;i<=n;i++){
            c[s[i][j]-'A']++;
        }
        int mx=0;
        for(int x=0;x<5;x++){
            mx=max(mx, c[x]*a[j]);
        }
        ans+=mx;
    }
    cout<<ans<<endl;
}