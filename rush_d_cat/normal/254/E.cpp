#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 402;
int n,v,m;
int a[N],dp[N][N],cnt[N][N]; pair<int,int> pre[N][N]; 
vector< pair<int,int> > vec[N];
vector<int> res[N];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=1;i<=m;i++) {
        int l,r,x; scanf("%d%d%d",&l,&r,&x);
        for(int j=l;j<=r;j++) vec[j].push_back(make_pair(x,i));
    }   
    for(int i=1;i<=n;i++) sort(vec[i].begin(), vec[i].end());
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=-1e9;
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<N;j++){
            int has = j + a[i];
            if (has < v) continue;
            has -= v; 

            if (dp[i][j] > dp[i+1][min(has, a[i])]) {
               dp[i+1][min(has, a[i])] = dp[i][j];
               cnt[i+1][min(has, a[i])] = 0;
               pre[i+1][min(has, a[i])] = make_pair(i,j);
            }
            for(int x=0;x<vec[i].size();x++) {
                if (has >= vec[i][x].first) {
                    has -= vec[i][x].first;
                    if (dp[i][j]+1+x > dp[i+1][min(has,a[i])]) {
                        dp[i+1][min(has,a[i])] = dp[i][j]+1+x;
                        cnt[i+1][min(has,a[i])] = x+1;
                        pre[i+1][min(has,a[i])] = make_pair(i,j);
                    } 
                }
            }
        }
    }
    int ans=0,bst=-1;
    for(int i=0;i<N;i++) {
        if (dp[n+1][i] > ans) {
            ans = dp[n+1][i]; bst = i;
        }
    }
    
    printf("%d\n", ans);
    int fi=n+1, se=bst;
    while(fi > 1) {
        int c = cnt[fi][se];
        for(int i=0;i<c;i++) {
           res[fi-1].push_back(vec[fi-1][i].second);
        }
        int x = pre[fi][se].first;
        int y = pre[fi][se].second;
        fi = x, se = y;
    } 
    for(int i=1;i<=n;i++) {
        printf("%d", res[i].size());
        for(auto x: res[i]) {
            printf(" %d", x);
        }
        printf("\n");
    }
}