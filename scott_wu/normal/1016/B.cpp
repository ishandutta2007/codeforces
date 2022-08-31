#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, M, Q;
string s, t;
int ps[MAXN];

bool works (int nloc)
{
    if (nloc + M > N) return false;
    for (int i = 0; i < M; i++)
        if (s[nloc+i] != t[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    cin >> s >> t;

    ps[0] = 0;
    for (int i = 0; i < N; i++)
    {
        ps[i+1] = ps[i];
        if (works (i))
            ps[i+1]++;
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        r -= (M - 1);
        if (l > r) cout << "0\n";
        else cout << ps[r+1] - ps[l] << "\n";
    }
}