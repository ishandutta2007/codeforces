#include <iostream>
using namespace std;
int n, x, cnt[5], ans;
int main()
{
    cin >> n; for(int i=1;i<=n;i++) cin >> x, cnt[x] ++;
    if(cnt[1]<cnt[2])
    {
        cnt[2] -= cnt[1], cnt[3] += cnt[1], ans += cnt[1];
        ans += cnt[2]/3*2,cnt[3] += cnt[2]/3*2, cnt[2]%=3;
        if(cnt[2] == 1) 
        {
            if(cnt[4] >= 1)
            {
                ans ++;
            } else if(cnt[3] >= 2) {
                ans += 2;
            } else {
                ans = -1;
            }
        } 
        if(cnt[2] == 2) 
        {
            ans += 2;
        }
    } else {
        cnt[1] -= cnt[2], cnt[3] += cnt[2], ans += cnt[2];
        ans += cnt[1]/3*2,cnt[3] += cnt[1]/3, cnt[1]%=3;
        if(cnt[1] == 1) 
        {
            if(cnt[3] >= 1)
            {
                ans ++;
            } else if(cnt[4] >= 2){
                ans += 2;
            } else {
                ans = -1;
            }
        } 
        if(cnt[1] == 2)
        {
            if(cnt[4] >= 1)
            {
                ans += 2;
            } else if(cnt[3] >= 2) {
                ans += 2;
            } else {
                ans = -1;
            }
        }
    }
    cout << ans << endl;
}