#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<long long> s;
    s.push_back(0ll);
    cin >> n;
    long long sum = 0ll;
    for(int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        s.push_back(sum);
    }
    long long ans = 0;
    for(int i = 0; i <= n; i++)
    {
        long long target = sum - s[i];
        if(target >= s[i] && binary_search(s.begin(), s.end(), target)) ans = s[i];
    }
    cout << ans;
}