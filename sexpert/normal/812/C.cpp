#include <bits/stdc++.h>
using namespace std;

long long n, S;
long long costo[100010];

int valid(long long k)
{
    vector<long long> costs;
    for(long long i = 0; i < n; i++)
    {
        long long t = costo[i] + k*(i + 1);
        if(t >= 0) costs.push_back(t);
    }
    sort(costs.begin(), costs.end());
    long long res = 0;
    for(int i = 0; i < k; i++)
    {
        res += costs[i];
    }
    return res;
}

int bs()
{
    int low = 0, high = min(n, 1500ll);
    while(low != high)
    {
        int mid = (low + high + 1)/2;
        if(valid(mid) <= S) low = mid;
        else high = mid - 1;
    }
    return low;
}

int main()
{ 
    cin >> n >> S;
    for(int i = 0; i < n; i++)
    {
        cin >> costo[i];
    }
    long long k = bs();
    if(k  == 0) cout << 0 << " " << 0;
    else cout << k << " " << valid(k);
}