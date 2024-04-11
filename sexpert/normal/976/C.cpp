#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y)
{
    if(x.first.first < y.first.first) return true;
    if(x.first.first == y.first.first && x.first.second > y.first.second) return true;
    return false;
}

int main()
{
    int n;
    vector<pair<pair<int, int>, int> > v;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        v.push_back(make_pair(make_pair(l, r), i));
    }
    sort(v.begin(), v.end(), comp);
    pair<int, int> ind = {-2, -2};
    for(int i = 0; i < n - 1; i++)
    {
        if(v[i].first.second >= v[i + 1].first.second) ind = make_pair(v[i + 1].second, v[i].second);
    }
    cout << ind.first + 1 << " " << ind.second + 1 << endl;
}