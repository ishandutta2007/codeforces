#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair< int, int > pii;

inline int
sum(pii val)
{
    return val.first + val.second;
}

pii
check(ll sq1, ll sq2)
{
    map< ll, int > min_time;
    int cur_time = 0;
    min_time[sq1] = cur_time;
    while (sq1 % 2 == 0) {
        sq1 /= 2;
        ++cur_time;
        min_time[sq1] = cur_time;
    }
    pii ans = make_pair(-1, -1);
    cur_time = 0;
    while (1) {
        if (min_time.find(sq2) != min_time.end()) {
            pii check_time(min_time[sq2], cur_time);
            if (ans == make_pair(-1, -1) || sum(ans) > sum(check_time)) {
                ans = check_time;
            }
        }
        if (sq2 % 2 == 0) {
            sq2 /= 2;
            ++cur_time;
        } else {
            break;
        }
    }
    return ans;
}

int
power_3(ll val)
{
    int res = 0;
    while (val % 3 == 0) {
        res++;
        val /= 3;
    }
    return res;
}

void
getVal(pair< ll, ll > cur, pii moves)
{
    //cout << moves.first << ' ' << moves.second << '\n';
    for (int i = 0; i < moves.second; ++i) {
        if (cur.first % 3 == 0) {
            cur.first = cur.first * 2 / 3;
        } else {
            cur.second = cur.second * 2 / 3;
        }
    }
    for (int i = 0; i < moves.first; ++i) {
        if (cur.first % 2 == 0) {
            cur.first /= 2;
        } else {
            cur.second /= 2;
        }
    }
    cout << cur.first << ' ' << cur.second << '\n';
}

int
main()
{
    ios_base::sync_with_stdio(false);
    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int pw1 = power_3(a1 * b1), pw2 = power_3(a2 * b2);
    ll cur_val = a1 * b1;
    pii ans1(-1, -1), ans2(-1, -1);
    for (int i = 0; i <= pw1; ++i) {
        ll cv1 = a2 * b2;
        for (int j = 0; j <= pw2; ++j) {
            pii v2 = check(cur_val, cv1);
            if (v2 != make_pair(-1, -1) && (ans1 == make_pair(-1, -1) || 
                        sum(ans1) + sum(ans2) > i + j + sum(v2))) {
                ans1 = make_pair(i, j);
                ans2 = v2;
            }
            cv1 = cv1 * 2 / 3;
        }
        cur_val = cur_val * 2 / 3;
    }
    cout << max(-1, sum(ans1) + sum(ans2)) << '\n';
    if (ans1 != make_pair(-1, -1)) {
        getVal(make_pair(a1, b1), make_pair(ans2.first, ans1.first));
        getVal(make_pair(a2, b2), make_pair(ans2.second, ans1.second));
    }
    return 0;
}