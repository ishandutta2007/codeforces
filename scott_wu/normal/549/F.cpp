#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const int MAXK = 1000100;

int N, K;
int nnext[MAXN], nprev[MAXN];

int arr[MAXN];
int pval[MAXN]; // sum of 1..i
vector <int> ps[MAXK];

int ord[MAXN];
ll ans;

inline bool cmp (int a, int b)
{
    return arr[a] < arr[b];
}

int loc (int val, int x) // first num at least val
{
    int lo = 0, hi = ps[x].size() - 1;
    if (ps[x][hi] < val) return hi + 1;
    
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (ps[x][mid] >= val)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int find (int lo, int hi, int x) // inc
{
    //cout << lo << " " << hi << " " << x << "\n";
    //cout << ps[x].size() << "\n";
    if (ps[x].size() == 0) return 0;
    hi++;
    
    //cout << loc (hi, x) - loc (lo, x) << "\n";
    return loc (hi, x) - loc (lo, x);
}

void solve (int cloc)
{
    int left = nprev[cloc], right = nnext[cloc];
    
    if (cloc - left <= right - cloc)
    {
        for (int i = left + 1; i <= cloc; i++)
        {
            int rval = (pval[i-1] + arr[cloc]) % K;
            ans += find (cloc, right - 1, rval);
        }
    }
    else
    {
        for (int i = cloc; i <= right - 1; i++)
        {
            int rval = ((pval[i] - arr[cloc]) % K + K) % K;
            ans += find (left, cloc - 1, rval);
        }
    }
    
    nnext[left] = right;
    nprev[right] = left;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        nnext[i-1] = i;
        nprev[i] = i - 1;
    }
    nnext[N] = N+1;
    nprev[N+1] = N;
    
    pval[0] = 0;
    ps[0].push_back (0);
    for (int i = 1; i <= N; i++)
    {
        pval[i] = (pval[i-1] + arr[i]) % K;
        ps[pval[i]].push_back (i);
    }
    
    for (int i = 0; i < N; i++)
        ord[i] = i + 1;
    sort (ord, ord + N, cmp);
    
    ans = 0;
    for (int i = 0; i < N; i++)
        solve(ord[i]);
    cout << ans - N << "\n";
    return 0;
}