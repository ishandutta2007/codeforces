#include <bits/stdc++.h>
using namespace std;

map<int, int> num;
int n, k;

bool check(int c)
{
    if(c == 0)
        return true;
    int tot = 0;
    for(auto p : num)
    {
        tot += p.second/c;
    }
    return (tot >= k);
}

int bs()
{
    int l = 0, r = n;
    while(l != r)
    {
        int m = (l + r + 1)/2;
        if(check(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        num[s]++;
    }
    vector<int> ans;
    int c = bs();
    for(auto p : num)
    {
        int x = p.second;
        while(x >= c)
        {
            ans.push_back(p.first);
            x -= c;
        }
    }
    for(int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
}