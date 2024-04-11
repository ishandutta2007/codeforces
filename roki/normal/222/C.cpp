#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;
vector<int> a, b;

bool read()
{
    if(!(cin >> n >> m))
        return false;
    a.resize(n);
    b.resize(m);
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, m)
        scanf("%d", &b[i]);
    return true;
}

vector<int> used(10000001, 1);

vector<int> faq(vector<int>& a)
{
    vector<int> res;
    forn (i, a.size())
    {
        while (a[i] % 2 == 0) 
        {
            a[i] /= 2;
            res.pb(2);
        }
        while (used[a[i]] != 1)
        {
            res.pb(used[a[i]]);
            int d = used[a[i]];
            a[i] /= d;
        }
        if(a[i] > 1)
            res.pb(a[i]);
    }
    return res;
}

void solve()
{
    vector<int> ca = a, cb = b;
    for (int i = 3; i < 10000000; i += 2)
    {
        if (used[i] != 1)
            continue;
        for (int j = 3 * i; j <= 10000000; j += (i << 1))
            used[j] = i;
    }
    vector<int> deg1(1e7 + 1, 0), deg2(1e7 + 1, 0);
    vector<int> faq1 = faq(a), faq2 = faq(b);
    sort (faq1.begin(), faq1.end());
    sort (faq2.begin(), faq2.end());
    int l1 = 0, l2 = 0;
    int a1 = 0, a2 = 0;
    while (l1 < faq1.size() && l2 < faq2.size())
    {
        if (faq1[l1] == faq2[l2])
            l1++, l2++;
        else
        {
            if (faq1[l1] < faq2[l2])
                deg1[faq1[l1++]]++;
            else
                deg2[faq2[l2++]]++;
        }
    }
    while (l1 < faq1.size())
        deg1[faq1[l1++]]++;
    while (l2 < faq2.size())
        deg2[faq2[l2++]]++;
    vector<int> ans1(n), ans2(m);
    forn (i, n)
    {
        ans1[i] = 1;
        while(ca[i] % 2 == 0)
        {
            ca[i] /= 2;
            if(deg1[2] > 0)
                ans1[i] *= 2, deg1[2]--;
        }
        while (used[ca[i]] > 1)
        {
            if (deg1[used[ca[i]]] > 0)
            {
                deg1[used[ca[i]]]--;
                ans1[i] *= used[ca[i]];
            }
            int d = used[ca[i]];
            ca[i] /= d;
        }
        if(ca[i] > 1 && deg1[ca[i]] > 0)
        {
            deg1[ca[i]]--;
            ans1[i] *= ca[i];
        }
    }
    forn (i, m)
    {
        ans2[i] = 1;
        while(cb[i] % 2 == 0)
        {
            cb[i] /= 2;
            if(deg2[2] > 0)
                ans2[i] *= 2, deg2[2]--;
        }
        while (used[cb[i]] > 1)
        {
            if (deg2[used[cb[i]]] > 0)
            {
                deg2[used[cb[i]]]--;
                ans2[i] *= used[cb[i]];
            }
            int d = used[cb[i]];
            cb[i] /= d;
        }
        if(cb[i] > 1 && deg2[cb[i]] > 0)
        {
            deg2[cb[i]]--;
            ans2[i] *= cb[i];
        }
    }
    cout << n << ' ' << m << endl;
    forn (i, n)
        printf("%d ", ans1[i]);
    cout << endl;
    forn (i, m)
        printf("%d ", ans2[i]);
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}