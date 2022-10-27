#include <iostream>
using namespace std;
#define N (5000000+10)
char s[N];

int n, t;
int pre[N], seg_L[N], seg_R[N];

bool ok(int x)
{
    pre[0] = x;
    int cnt = 0, ans = 0;
    int last_house = -1;

    for (int i = 1; i <= n; i ++) 
    {
        if (s[i] == '.') pre[i] = pre[i-1];
        if (s[i] == 'H') pre[i] = pre[i-1] - 1;
        if (s[i] == 'S') pre[i] = pre[i-1] + 1;

        if (s[i] == 'H' || (pre[i] == 0 && s[i] == 'S')) last_house = i;

        if ( pre[i] < 0 && pre[i-1] >= 0 ) 
        {
            seg_L[++cnt] = i;
        }

        if ( pre[i] >= 0 && pre[i-1] < 0 ) 
        {
            seg_R[cnt] = i; 
            ans += 2 * (seg_R[cnt] - seg_L[cnt]);
        }
    }
    ans += last_house;
    if (pre[n] < 0) return 0;

    int result = ans;
    
    //cout << "last house: " << last_house << endl; 
    //cout << result << endl;
    
    for (int i = cnt; i >= 1; i --) 
    {
        //printf("%d %d\n", seg_L[i], seg_R[i]);
        ans -= 2 * (seg_R[i] - seg_L[i]);
        //printf("%d\n", ans);
        //printf("%d\n", ans + last_house - seg_L[i]);
        result = min(result, ans + last_house - seg_L[i]);
    }   

    //cout << result << endl;

    return result <= t;
}

int main() {
    scanf("%d %d", &n, &t);
    scanf("%s", s + 1);

    int L = 0, R = 2000000+1; //ok(0); return 0;

    while (R - L > 1) 
    {
        int mid = (L + R) >> 1;
        if (ok (mid)) 
        {
            R = mid;
        } else {
            L = mid;
        }
    }
    if (ok(L)) R = L;
    if (R >= 500000) cout << -1 << endl;
    else cout << R << endl;

}