#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
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

string a, b;

inline bool read()
{
    if(!(cin >> a >> b))
        return false;
    return true;
}

inline void solve()
{
    char m = '0';
    forn (i, a.size())
        m = max(m, a[i]);
    forn (i, b.size())
        m = max(m, b[i]);
    int os = m - '0' + 1;
    vector<int> A(a.size());
    forn (i, a.size())
        A[i] = a[i] - '0';
    vector<int> B(b.size());
    forn (i, b.size())
        B[i] = b[i] - '0';
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    vector<int> ans;
    int p = 0;
    forn (i, max(A.size(), B.size()))
    {
        ans.push_back(p);
        p = 0;
        if(i < A.size())
            ans[i] += A[i];
        if(i < B.size())
            ans[i] += B[i];
        if(ans[i] >= os)
            ans[i] -= os, p = 1;
    }
    cout << ans.size() + p << endl;
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