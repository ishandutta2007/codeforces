
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int n;
int a, b, c;
int acnt, bcnt, ccnt, abcnt, accnt, bccnt;

/*while (ccnt) {
    ans++; ccnt--;
    if (!acnt && !bcnt) {
        abcnt--;
    } else {
        if (acnt) acnt--;
        if (bcnt) bcnt--;
        else if (acnt) acnt--;
    }
}
while (acnt || bcnt || abcnt) {
    if (acnt || bcnt || !abcnt) {
        ans++;
        if (acnt) acnt--;
        if (bcnt) bcnt--;
        else if (acnt) acnt--;
        if (abcnt) abcnt--;
        else if (bcnt) bcnt--;
        else if (acnt) acnt--;
    } else {
        ans += abcnt / 2;
        ans += abcnt % 2;
        break;
    }
}*/

bool check(int cnt)
{
    int ta = acnt, tb = bcnt, tab = abcnt;
    int oldcnt = cnt;
    cnt -= ccnt;
    while (cnt) {
        cnt--;
        if (tab) tab--;
        else if (tb) tb--;
        else if (ta) ta--;
    }
    int abtim = tab;
    while (ta || tb) {
        abtim++;
        if (ta) ta--;
        if (tb) tb--;
        else if (ta) ta--;
    }
    return abtim <= oldcnt;
}

bool check2(int cnt)
{
    int ta = acnt, tb = bcnt, tc = ccnt;
    int oldcnt = cnt;
    while (cnt) {
        cnt--;
        if (tc) tc--;
        else if (tb) tb--;
        else if (ta) ta--;
    }
    int abtim = tc;
    while (ta || tb) {
        abtim++;
        if (ta) ta--;
        if (tb) tb--;
        else if (ta) ta--;
    }
    return abtim <= oldcnt;
}

int main()
{
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int val; scanf("%d", &val);
        if (val > a + b + c) {
            printf("-1"); return 0;
        } else if (val > b + c) {
            ans++;
        } else if (val > a + c) {
            bccnt++;
        } else if (val > max(c, a + b)) {
            accnt++;
        } else if ((a + b) >= c && val > c) {
            abcnt++;
        } else if ((a + b) >= c && val > b) {
            ccnt++;
        } else if ((a + b) < c && val > a + b) {
            ccnt++;
        } else if ((a + b) < c && val > b) {
            abcnt++;
        } else if (val > a) {
            bcnt++;
        } else {
            acnt++;
        }
    }
    ans += bccnt; acnt = max(acnt - bccnt, 0);
    while (accnt) {
        ans++; accnt--;
        if (bcnt) {bcnt--;
        } else if (acnt) {acnt--;}
    }
    if (c > a + b) {
        int l = ccnt, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans += l;
    } else {
        while (abcnt) {
            ans++; abcnt--;
            if (ccnt) ccnt--;
            else if (bcnt) bcnt--;
            else if (acnt) acnt--;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check2(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans += l;
    }
    printf("%d", ans);
    return 0;
}