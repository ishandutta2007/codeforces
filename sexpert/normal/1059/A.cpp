#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, a;
    cin >> n >> l >> a;
    vector<int> v;
    v.push_back(0);
    for(int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        v.push_back(s);
        v.push_back(s + t);
    }
    v.push_back(l);
    int ans = 0;
    for(int i = 0; i < v.size(); i += 2)
        ans += (v[i + 1] - v[i])/a;
    cout << ans << endl;
}