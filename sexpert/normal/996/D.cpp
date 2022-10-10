#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v)
{
    if(v.empty()) return 0;
    if(v[0] == v[1])
    {
        v.erase(v.begin(), v.begin() + 2);
        return solve(v);
    }
    int a = v[0];
    for(int i = 1;;i++)
    {
        if(v[i] == a)
        {
            v.erase(v.begin() + i);
            v.erase(v.begin());
            return i - 1 + solve(v);
        }
    }
}

int main()
{
    int n, c;
    cin >> n;
    vector<int> s;
    for(int i = 0; i < 2*n; i++)
    {
        cin >> c;
        s.push_back(c);
    }
    cout << solve(s);
}