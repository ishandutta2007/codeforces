#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[1005], d[1005];
    int n;
    cin >> n;
    a[0] = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        d[i] = a[i + 1] - a[i];
    }
    int num = 0;
    vector<int> ans;
    for(int k = 1; k <= n; k++)
    {
        bool b = true;
        for(int i = 0; i + k < n; i++)
        {
            if(d[i] != d[i + k])
            {
                b = false;
                break;
            }
        }
        if(b)
        {
            num++;
            ans.push_back(k);
        }
    }
    cout << num << "\n";
    for(auto n : ans)
        cout << n << " ";
}