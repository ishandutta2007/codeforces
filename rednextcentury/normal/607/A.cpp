#include <bits/stdc++.h>
#define F first
#define S second
using namespace std ;

const int MAXN = INT_MAX;
const int MAX = 1e6 + 9;

int pos[MAX], dp[MAX];
pair <int, int> arr[MAX];

int shit (int lo, int hi, int item) {
    int ans=-1;
    while (lo<=hi) {
        int mid =  (hi + lo) / 2;
        if (arr[mid].F <= item)
            ans=mid,lo = mid+1;
        else
            hi = mid-1;
    }
    return ans;
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[i].F = x, arr[i].S = y;
        pos[x] = i;
    }
    sort(arr + 1, arr + n + 1);
    int ans = MAXN;
    for (int i = 1 ; i <= n ; i++) {
        int t ;
        if (i == 1) dp[i] = 0;
        else {
            int p = arr[i].F, dis = arr[i].S;
            if (dis > p) dis = p + 1;
            t = shit (1, n, p - dis - 1);
            if (t==-1)
                dp[i]=i-1;
            else
            dp[i] = dp[t] + (i - t - 1);
        }
        ans = min (ans, dp[i] + (n - i));
        //cout << dp[i] << " " << t << " " << dp[i] + (n - i) << endl;
    }
    cout << ans << endl;
}