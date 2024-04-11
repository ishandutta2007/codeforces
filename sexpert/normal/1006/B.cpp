#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n;
    vector<pair<int, int>> d, sd;
    vector<int> pos;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d.push_back(make_pair(-x, i));
    }
    sd = d;
    sort(sd.begin(), sd.end());
    //for(auto p : sd) cout << p.first << " " << p.second << endl;
    for(int i = 0; i < k; i++)
    {
        pos.push_back(sd[i].second);
    }
    sort(pos.begin(), pos.end());
    int sum = 0;
    for(auto p : pos) sum -= d[p].first;
    cout << sum << endl;
    if(k == 1)
    {
        cout << n;
        return 0;
    }
    cout << pos[1] << " ";
    for(int i = 1; i < k - 1; i++) cout << pos[i + 1] - pos[i] << " ";
    cout << n - pos[k - 1];
}