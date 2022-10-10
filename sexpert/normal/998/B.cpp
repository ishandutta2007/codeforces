#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, b, cnt = 0;
    vector<int> a, v;
    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i]%2)cnt++;
        else cnt--;
        if(cnt == 0) v.push_back(abs(a[i + 1] - a[i]));
    }
    sort(v.begin(), v.end());
    int cost = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(cost + v[i] > b)
        {
            cout << i;
            return 0;
        }
        else cost += v[i];
    }
    cout << v.size();
}