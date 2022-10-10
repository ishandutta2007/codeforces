#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<long long> guys;
    int ans = 1;
    vector<int> ansbois;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        guys.push_back(x);
    }
    sort(guys.begin(), guys.end());
    for(int i = 0; i < guys.size(); i++)
    {
        for(long long ex = 0; ex < 33; ex++)
        {
            long long t = pow(2ll, ex);
            long long k = guys[i];
            if(binary_search(guys.begin(), guys.end(), k + t))
            {
                ans = max(2, ans);
                if(ans == 2) ansbois = {k, k + t};
                if(binary_search(guys.begin(), guys.end(), k + 2*t))
                {
                    ans = 3;
                    ansbois = {k, k + t, k + 2*t};
                }
            }
        }
    }
    if(ans == 1) ansbois = {guys[0]};
    cout << ans << endl;
    for(auto guy : ansbois)
    {
        cout << guy << " ";
    }
}