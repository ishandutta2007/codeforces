#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int f = 1)
{
    if(n == 1)
    {
        vector<int> v = {f};
        return v;
    }
    if(n == 3)
    {
        vector<int> v = {f, f, 3*f};
        return v;
    }
    vector<int> res;
    for(int i = 1; i <= (n + 1)/2; i++)
        res.push_back(f);
    vector<int> ppend = solve(n/2, 2*f);
    for(int x : ppend)
        res.push_back(x);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v = solve(n);
    for(int x : v)
        cout << x << " ";
}