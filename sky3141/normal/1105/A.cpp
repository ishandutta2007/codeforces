#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int MAXN = 1000 + 9;

int ans = 1000000000;
int at;
int n;
int a[MAXN];

int cost(int x, int y)
{
    if(x > y) std::swap(x, y);
    return x == y ? 0 : y - x - 1;
}

int main()
{
#ifdef ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int t=1; t<=100; ++t)
    {
        int sum = 0;
        for(int i=0; i<n; ++i)
        {
            sum += cost(t, a[i]);
        }
        if(sum < ans)
        {
            ans = sum;
            at = t;
        }
    }
    cout << at << ' ' << ans << std::endl;

    return 0;
}