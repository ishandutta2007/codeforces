#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    v.push_back(0);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(1001);
    int ans = 0, chn = 0;
    for(int i = 0; i < v.size(); i++)
    {
        chn++;
        if(i == v.size() - 1 || v[i + 1] != v[i] + 1)
        {
            ans = max(ans, chn);
            chn = 0;
        }
    }
    cout << max(0, ans - 2) << endl;
}