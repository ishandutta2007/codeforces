#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        b.push_back(make_pair(a, i + 1));
    }
    sort(b.begin(), b.end());
    //for(auto p : b) cout << p.first << " " << p.second << endl;
    if(n == 1) cout << -1;
    else if(n == 2 && b[0].first == b[1].first) cout << -1;
    else
    {
        cout << 1 << endl << b[0].second << endl;
    }
}