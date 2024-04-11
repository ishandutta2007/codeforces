#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

/* price, beauty */

struct Info {
    int first, second, maxv;
};

Info make_info(int first, int second, int maxv)
{
    Info inf;
    inf.first = first; inf.second = second; inf.maxv = maxv;
    return inf;
}

vector<Info > coins;
vector<Info > diamonds;

int n, c, d;

int work(vector<Info> &l, int maxcost)
{
    int a = 0;
    int b = l.size() - 1;
    int ans = 0;
    multiset<int> values;
    for (int i = 0; i < l.size(); i++) values.insert(-l[i].second);
    while (a < l.size()) {
        while (b >= 0 && l[b].first + l[a].first > maxcost) {
            values.erase(values.find(-l[b].second));
            b--;
        }
        if (a <= b) values.erase(values.find(-l[a].second));
        if (b < 0) break;
        if (!values.empty()) ans = max(ans, l[a].second + -(*(values.upper_bound(-100000000))));
        if (a <= b) values.insert(-l[a].second);
        a++;
    }
    return ans;
}

bool cmp(Info a, Info b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    scanf("%d%d%d", &n, &c, &d);
    for (int i = 1; i <= n; i++) {
        char s[5]; int b, p;
        scanf("%d%d%s", &b, &p, s);
        if (s[0] == 'C') {
            coins.push_back(make_info(p, b, 0));
        } else {
            diamonds.push_back(make_info(p, b, 0));
        }
    }
    sort(coins.begin(), coins.end(), cmp);
    sort(diamonds.begin(), diamonds.end(), cmp);
    int ans = 0;
    int max_coin = 0, max_diamond = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i].first <= c) max_coin = max(max_coin, coins[i].second);
    }
    for (int i = 0; i < diamonds.size(); i++) {
        if (diamonds[i].first <= d) max_diamond = max(max_diamond, diamonds[i].second);
    }
    if (max_coin && max_diamond) ans = max_coin + max_diamond;
    if (coins.size() >= 2) ans = max(ans, work(coins, c));
    if (diamonds.size() >= 2) ans = max(ans, work(diamonds, d));
    printf("%d", ans);
    return 0;
}