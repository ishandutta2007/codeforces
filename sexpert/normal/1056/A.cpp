#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> current, newset;
    for(int i = 0; i < n; i++)
    {
        newset.clear();
        int r;
        cin >> r;
        for(int j = 0; j < r; j++)
        {
            int x;
            cin >> x;
            if(i == 0 || current.count(x))
                newset.insert(x);
        }
        current = newset;
    }
    for(auto x : newset)
        cout << x << " ";
}