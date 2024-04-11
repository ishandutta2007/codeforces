#include <bits/stdc++.h>
using namespace std;

long long a[200005];
int n;

int bs(long long k)
{
    int low = 0, high = n;
    while(low != high)
    {
        int mid = (low + high + 1)/2;
        if(a[mid] <= k) low = mid;
        else high = mid - 1;
    }
    return low;
}

int main()
{
    int q;
    long long s = 0;
    cin >> n >> q;
    a[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s += t;
        a[i + 1] = s;
    }
    long long tot = 0;
    for(int i = 0; i < q; i++)
    {
        long long k;
        cin >> k;
        tot += k;
        int m = bs(tot);
        if(m == n) {tot = 0; m = 0;}
        cout << n - m << endl;
    }
}