#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    vector<vector<int>> seqs;
    vector<pair<int, pair<int, int>>> dude;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        seqs.push_back({});
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            seqs[i].push_back(x);
        }
    }
    bool found = false;
    for(int i = 0; i < k; i++)
    {
        int sum = 0;
        for(int x : seqs[i])
        {
            sum += x;
        }
        for(int j = 0; j < seqs[i].size(); j++)
        {
            dude.push_back(make_pair(sum - seqs[i][j], make_pair(i, j)));
        }
    }
    sort(dude.begin(), dude.end());
    for(int i = 0; i < dude.size() - 1; i++)
    {
        auto t1 = dude[i];
        auto t2 = dude[i + 1];
        if(t1.first == t2.first && t1.second.first != t2.second.first)
        {
            cout << "YES\n";
            auto p1 = t1.second;
            auto p2 = t2.second;
            cout << p1.first + 1 << " " << p1.second + 1 << "\n" << p2.first + 1 << " " << p2.second + 1;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}