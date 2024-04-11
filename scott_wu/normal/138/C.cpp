#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 100100;
const int MAXM = 10100;

struct bigd
{
    double val;
    int exp;
    
    bigd ()
    {
        val = 1.0;
        exp = 0;
    }
};

inline bigd mult (bigd left, double right)
{
    left.val *= right;
    while (left.val >= 10)
    {
        left.val /= 10;
        left.exp++;
    }
    while (left.val < 1)
    {
        left.val *= 10;
        left.exp--;
    }
    return left;
}

inline double mult2 (bigd left, double right)
{
    right *= left.val;
    for (int i = 0; i < left.exp; i++)
        right *= 10;
    for (int i = 0; i > left.exp; i--)
        right /= 10;
    return right;
}

struct mush
{
    int loc;
    int pow;
};

struct ts
{
    int loc;
    double change;
};

mush shroom[MAXM];
vector <ts> tree;
vector <pair <int, int> > zlist;

inline bool operator < (mush left, mush right)
{
    return left.loc < right.loc;
}

inline bool operator < (ts left, ts right)
{
    return left.loc < right.loc;
}

int n, m;

int main()
{
    cin >> n >> m;
    ts temp;
    for (int i = 0; i < n; i++)
    {
        int a, h, l, r;
        cin >> a >> h >> l >> r;
        if (l > 0)
        {
            if (l == 100)
            {
                zlist.push_back (make_pair (a-h, 1));
                zlist.push_back (make_pair (a, -1));
            }
            else
            {
                temp.loc = a - h;
                temp.change = 1.0 - l / 100.0;
                tree.push_back (temp);
                temp.loc = a;
                temp.change = 1.0 / (1.0 - l / 100.0);
                tree.push_back (temp);
            }
        }
        if (r > 0)
        {
            if (r == 100)
            {
                zlist.push_back (make_pair (a+1, 1));
                zlist.push_back (make_pair (a+h+1, -1));
            }
            else
            {
                temp.loc = a + 1;
                temp.change = 1.0 - r / 100.0;
                tree.push_back (temp);
                temp.loc = a + h + 1;
                temp.change = 1.0 / (1.0 - r / 100.0);
                tree.push_back (temp);
            }
        }
    }
    sort (tree.begin(), tree.end());
    sort (zlist.begin(), zlist.end());
    for (int i = 0; i < m; i++)
        cin >> shroom[i].loc >> shroom[i].pow;
    sort (shroom, shroom + m);
    bigd prob;
    prob.val = 1.0; prob.exp = 0;
    int cur = 0, zcur = 0;
    double ans = 0.0;
    int z = 0;
    for (int i = 0; i < m; i++)
    {
        while (cur < tree.size() && shroom[i].loc >= tree[cur].loc)
        {
            prob = mult (prob, tree[cur].change);
            cur++;
        }
        while (zcur < zlist.size() && shroom[i].loc >= zlist[zcur].first)
        {
            z += zlist[zcur].second;
            zcur++;
        }
        if (z == 0)
            ans += mult2 (prob, shroom[i].pow);
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}