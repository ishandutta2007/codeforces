#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=505;

int suf[sz], dp[sz][sz];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &dp[i][i]);
    for(int k=1; k<n; k++) {
        for(int i=0; i<n-k; i++) {
            int x = i, y = i+k;
            for(int j=x; j<y; j++) {
                if(dp[x][j]==dp[j+1][y] && dp[x][j]) {
                    dp[x][y] = dp[x][j]+1;
                }
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        suf[i] = n-i;
        for(int j=i; j<n; j++) {
            if(dp[i][j]) {
                suf[i] = min(suf[i], 1+suf[j+1]);
            }
        }
    }
    cout << suf[0];
}