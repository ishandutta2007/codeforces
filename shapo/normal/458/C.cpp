#include <set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int MAXN = 100500;

struct Node
{
    int y;
    ll cost;
    ll sumAll;
    int cnt;
    int l, r;
};

Node sm[MAXN];
int smCnt;

void
update(int node)
{
    sm[node].cnt = sm[sm[node].l].cnt + sm[sm[node].r].cnt + 1;
    sm[node].sumAll = sm[sm[node].l].sumAll + sm[sm[node].r].sumAll + sm[node].cost;
}

void
split(int x, ll sCost, int &a, int &b)
{
    int ra = 0, rb = 0;
    if (x == 0) {
        return;
    }
    if (sm[x].cost <= sCost) {
        split(sm[x].r, sCost, ra, b);
        sm[x].r = ra;
        a = x;
        update(x);
    } else {
        split(sm[x].l, sCost, a, rb);
        sm[x].l = rb;
        b = x;
        update(x);
    }
}

int
mergeTree(int t1, int t2)
{
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    if (sm[t1].y >= sm[t2].y) {
        sm[t1].r = mergeTree(sm[t1].r, t2);
        update(t1);
        return t1;
    }
    sm[t2].l = mergeTree(t1, sm[t2].l);
    update(t2);
    return t2;
}

int
addTree(int root, ll cost)
{
    ++smCnt;
    sm[smCnt].cost = cost;
    sm[smCnt].l = sm[smCnt].r = 0;
    sm[smCnt].cnt = 1;
    sm[smCnt].sumAll = cost;
    sm[smCnt].y = rand();
    int a, b, c;
    a = b = c = 0;
    split(root, cost, a, b);
    c = mergeTree(a, smCnt);
    root = mergeTree(c, b);
    return root;
}

ll
getSum(int root, int cnt)
{
    //cerr << "getSum cnt = " << cnt << endl;
    int curV = root;
    ll sum = 0LL;
    if (cnt == 0) {
        return 0LL;
    } else if (sm[root].cnt < cnt) {
        //cerr << "Fail" << endl;
        return -1LL;
    }
    while (curV != 0 && cnt != 0) {
        int left_sz = sm[sm[curV].l].cnt;
        if (left_sz + 1 == cnt) {
            sum += sm[sm[curV].l].sumAll + sm[curV].cost;
            return sum;
        } else if (left_sz + 1 > cnt) {
            curV = sm[curV].l;
        } else {
            sum += sm[sm[curV].l].sumAll + sm[curV].cost;
            cnt -= left_sz + 1;
            curV = sm[curV].r;
        }
    }
    return 0LL;
}

multiset< int > cands[MAXN];
set< int > allCands;
int n;
int curCnt = 0;

int
main()
{
    srand(42424243);
    ios_base::sync_with_stdio(false);
    ll res = 0LL;
    ll curCost = 0LL;
    cin >> n;
    smCnt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            ++curCnt;
        } else {
            cands[a].insert(b);
            allCands.insert(a);
            curCost += b;
        }
    }
    curCnt = n;
    int root = 0;
    res = curCost;
    for (int curLevel = 1; curLevel <= n; ++curLevel) {
        vector< int > eraseCands;
        for (const auto curCand : allCands) {
            auto &curSet = cands[curCand];
            auto it = curSet.end(); --it;
            ll nextVal = *it;
            curSet.erase(it);
            curCost -= nextVal;
            curCnt--;
            root = addTree(root, nextVal);
            if (curSet.empty()) {
                eraseCands.push_back(curCand);
            }
        }
        for (auto x : eraseCands) {
            //cerr << "delete " << x << endl;
            allCands.erase(x);
        }
        //cerr << "with level " << curLevel + 1 << " we have " << curCnt << " votes" << endl;
        //cerr << "with sum " << curCost << endl;
        ll addSum = getSum(root, max(curLevel + 1 - curCnt, 0));
        if (addSum != -1LL) {
            res = min(res, curCost + addSum);
        }
    }
    cout << res << '\n';
    return 0;
}