#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int mx = 0, idx = 0;
    for(int i = 0; i < k; i++)
    {
        while(idx < n && a[idx] == mx)
            idx++;
        if(idx == n)
            cout << 0 << endl;
        else
        {
            cout << a[idx] - mx << endl;
            mx = a[idx];
        }
    }
}