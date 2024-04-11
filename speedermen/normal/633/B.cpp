#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

long long cnt(long long x) {
    long long r = 0;
    while (x > 0) {
        r += x / 5;
        x /= 5;
    }
    return r;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    int m;
    cin >> m;
    vector < int > ans;
    for (int i = 1; i <= 500005; ++i)
        if (cnt(i) == m)
            ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}