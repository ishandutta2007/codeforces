#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> x, y;
    set<int> z;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
        z.insert(a);
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        y.push_back(a);
        z.insert(a);
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int a = x[i], b = y[j];
            if(z.count(a^b)) count++;
        }
    }
    if(count % 2) cout << "Koyomi";
    else cout << "Karen";
}