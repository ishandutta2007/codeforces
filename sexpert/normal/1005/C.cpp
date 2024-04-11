#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    vector<int> a;
    cin >> n;
    a.push_back(1<<31);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(1<<31 - 1);
    sort(a.begin(), a.end());
    //for(auto x : a) cout << x << " ";
    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        bool b = false;
        for(int j = 0; j <= 30; j++)
        {
            if(binary_search(a.begin(), a.end(), (1ll << j) - x))
            {
                if((1ll << j) - x != x) b = true;
                else
                {
                    if(a[i - 1] == x || a[i + 1] == x) b = true;
                }
            }
        }
        if(!b) count++;
    }
    cout << count;
}