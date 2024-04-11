#include <iostream>
#include <algorithm>
using namespace std;
const int N=10000+10;
const int INF=1000000007;
int n,l,r;
int dp[N];

struct Item{ 
    int h,k; 
} it[N];

bool cmp(Item A,Item B) {
    if (A.k == B.k)
        return A.h > B.h;
    return A.k < B.k;
}

int main() {
    scanf("%d%d%d",&n,&l,&r);
    int tot = 0;

    for(int i=1;i<=n;i++) {
        scanf("%d",&it[i].h);
        tot += it[i].h;
    }
    int t = r; r = tot - l; l = tot - t;

    for(int i=1;i<=n;i++) 
        scanf("%d",&it[i].k);
    
    sort(it+1,it+1+n,cmp);

    int ans=0;

    for(int j=1;j<=tot;j++) 
        dp[j] = -INF;

    for(int i=1;i<=n;i++){
        for(int j=tot;j>=1;j--){

            if (j-it[i].h>=0) {
                if (j<=r&&j>=l&&it[i].k==1) {
                    dp[j]=max(dp[j], dp[j-it[i].h]+1);
                } else
                    dp[j]=max(dp[j], dp[j-it[i].h]);
                ans=max(ans,dp[j]);
            }
        }
    }
    cout << ans << endl;

}