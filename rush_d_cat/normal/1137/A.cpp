#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 2000 + 10;

vector<int> r[N], c[N];
int n,m,x[N][N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        scanf("%d", &x[i][j]);
        r[i].push_back(x[i][j]);
        c[j].push_back(x[i][j]);
    }

    for(int i=1;i<=n;i++){
        sort(r[i].begin(), r[i].end());
        r[i].erase(unique(r[i].begin(),r[i].end()), r[i].end());
    }
    for(int i=1;i<=m;i++){
        sort(c[i].begin(), c[i].end());
        c[i].erase(unique(c[i].begin(),c[i].end()), c[i].end());
    }


    //rintf("# %d\n", upper_bound(r[1].begin(), r[1].end(), 1) - r[1].begin());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            int c1 = lower_bound(r[i].begin(), r[i].end(), x[i][j]) - r[i].begin();
            int d1 = r[i].size() - (upper_bound(r[i].begin(), r[i].end(), x[i][j]) - r[i].begin());

            int c2 = lower_bound(c[j].begin(), c[j].end(), x[i][j]) - c[j].begin(); 
            int d2 = c[j].size() - (upper_bound(c[j].begin(), c[j].end(), x[i][j]) - c[j].begin());
            int ans = max(c1,c2) + 1 + max(d1,d2);

            //printf("%d %d %d %d\n", c1, c2, d1, d2);
            printf("%d ", ans);
        }
        printf("\n");
    }
}