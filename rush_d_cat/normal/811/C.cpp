#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> st;
int n, a[5002], dp[5002], pre[5002], cnt[5002], c[5002];
int vis[5002];
int max(int x, int y) {return x<y?y:x;}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        cnt[a[i]] ++;
    }
    for(int i=1;i<=n;i++) {
        st.clear();
        for(int j=0;j<=5000;j++) {
            c[j] = cnt[j];
            vis[j] = 0;
        }

        int zero = 0, ans = 0, sz = 0;
        for(int j=i-1;j>=0;j--) {
            if(vis[a[j+1]] == 0) sz ++;
            vis[a[j+1]] = 1;

            if(c[a[j+1]] == cnt[a[j+1]]) ans ^= a[j+1];
            c[a[j+1]] --; 
            if(c[a[j+1]] == 0) zero ++;
            int tmp = (sz == zero)?ans:0;
            dp[i] = max(dp[j] + tmp, dp[i]);
        }

    }
    cout << dp[n] << endl;

}