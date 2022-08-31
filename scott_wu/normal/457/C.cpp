#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXP = (1 << 18) + 100;
const int P = (1 << 17);

int N;
int a[MAXN], b[MAXN];
vector <int> v[MAXN];
vector <int> add[MAXN];

int seg[MAXP];
int ucnt[MAXP];

void upd (int cloc, int x, int y)
{
    cloc += P;
    
    while (cloc > 0)
    {
        seg[cloc] += x;
        ucnt[cloc] += y;
        cloc /= 2;
    }
}

int usum (int cloc)
{
    cloc += P;
    int res = 0;
    while (cloc > 1)
    {
        if (cloc % 2 == 1)
            res += ucnt[cloc-1];
        cloc /= 2;
    }
    return res;
}

int ssum (int cloc)
{
    cloc += P;
    int res = 0;
    while (cloc > 1)
    {
        if (cloc % 2 == 1)
            res += seg[cloc-1];
        cloc /= 2;
    }
    return res;
}

int floc (int x) // find n s.t. psum(ucnt[n]) = x
{
    if (usum (N) < x)
        return 1e9;
    
    int lo = 0, hi = N;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (usum (mid) >= x)
            hi = mid;
        else
            lo = mid + 1;
    }
    return ssum (lo);
}

int ord[MAXN];

int fnext (int x)
{
    int lo = 0, hi = N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (ord[mid] < x || (ord[mid] == x && ucnt[mid+P] == 1))
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}


int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        ord[i] = b[i];
    }
    
    sort (ord, ord + N);
    
    //cout << 3;
    
    int ctot = N;
    int csum = 0;
    for (int i = 1; i < MAXN; i++)
    {
        sort (v[i].begin(), v[i].end());
        reverse (v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); j++)
        {
            csum += v[i][j];
            add[j].push_back (v[i][j]);
        }
    }
    
    //cout << 4;
    
    int ans = 2e9;
    for (int i = 0; i < MAXN; i++)
    {
        int need = i + 1;
        
        ans = min (ans, csum + floc (need - ctot));
        
        for (int j = 0; j < add[i].size(); j++)
        {
            ctot--;
            csum -= add[i][j];
            upd (fnext (add[i][j]), add[i][j], 1);
        }
    }
    
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}