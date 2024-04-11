#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    int a[100010];
    set<int> res, divs;
    vector<int> guys;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        res.insert(a[i]%k);
    }
    for(auto x : res) guys.push_back(x);
    if(guys.size() == 1 && guys[0] == 0)
    {
        cout << 1 << '\n' << 0;
        return 0;
    }
    int m;
    if(guys.size() == 1) m = guys[0];
    else m = guys[1];
    for(int i = 1; i*i <= k; i++)
    {
        if(k%i == 0)
        {
            divs.insert(i);
            divs.insert(k/i);
        }
    }
    int d = 1;
    bool f;
    for(auto x : divs)
    {
        f = true;
        for(int i = 0; i < guys.size(); i++)
        {
            if(guys[i] % x != 0)
            {
                f = false;
                break;
            }
        }
        if(f) d = x;
    }
    cout << k/d << endl;
    for(int i = 0; i < k/d; i++) cout << d*i << " ";
}