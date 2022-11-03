/*
ID: Sfiction
OJ: CF
PROB: 490A
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=5000+100;

int n;
vector<int> a[3];

int main(){
    int t;
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&t);
        a[t-1].push_back(i);
    }
    int ans=min(a[0].size(),min(a[1].size(),a[2].size()));
    printf("%d",ans);
    for (int i=0;i<ans;++i)
        printf("\n%d %d %d",a[0][i],a[1][i],a[2][i]);
    return 0;
}