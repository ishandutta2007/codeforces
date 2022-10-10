#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> val;
    vector<int> seq;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        seq.push_back(x);
    }
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        val.insert(x);
    }
    for(auto x : seq) if(val.count(x)) cout << x << " ";
}