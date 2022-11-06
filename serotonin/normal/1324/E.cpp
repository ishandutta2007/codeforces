#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2005;

int n, h, l, r, a[sz], dp[sz][sz];

int fnc(int curt, int pos)
{
    if(pos==n) return 0;
    if(dp[curt][pos]<0) {
        int nxt = (curt + a[pos]) % h;
        int zer = fnc(nxt, pos + 1);
        if(l <= nxt && nxt <= r) zer++;
        nxt--;
        if(nxt < 0) nxt += h;
        int one = fnc(nxt, pos + 1);
        if(l <= nxt && nxt <= r) one++;
        dp[curt][pos] = max(one, zer);
    }
    return dp[curt][pos];
}

int main()
{
    cin >> n >> h >> l >> r;
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    cout << fnc(0,0);
}