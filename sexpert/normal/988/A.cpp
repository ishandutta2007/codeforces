#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> ratings;
    vector<int> indices;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(!ratings.count(x))
        {
            ratings.insert(x);
            indices.push_back(i + 1);
        }
    }
    if(ratings.size() < k) cout << "NO";
    else
    {
        cout << "YES\n";
        for(int i = 0; i < k; i++)
        {
            cout << indices[i] << " ";
        }
    }
}