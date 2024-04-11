#include <bits/stdc++.h>
using namespace std;

const long long ub = 1e18;

long long bs(long long r)
{
    long long low = 0, high = min(r, 1000000000ll);
    while(low != high)
    {
        long long mid = (low + high + 1)/2;
        if(mid*mid <= r)
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    set<long long> pp, sq;
    vector<long long> op = {0};
    for(int i = 1; i <= 1000; i++)
    {
        sq.insert(i*i);
    }
    for(long long a = 2; a < 1000001; a++)
    {
        if(sq.count(a))
            continue;
        long long x = a;
        while(x <= ub/(a*a))
        {
            x *= (a*a);
            pp.insert(x);
        }
    }
    int ct = 0;
    for(auto x : pp)
        op.push_back(x);
    int q;
    cin >> q;
    while(q--)
    {
        long long l, r, ans = 0;
        cin >> l >> r;
        ans = bs(r) - bs(l - 1);
        ans += upper_bound(op.begin(), op.end(), r) - lower_bound(op.begin(), op.end(), l);
        cout << ans << endl;
    }
}