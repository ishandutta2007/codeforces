#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    int n, d;
    cin >> n >> d;
    vector<int> hots;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hots.push_back(x);
    }
    int pos;
    bool b;
    for(int i = 0; i < n; i++)
    {
        b = false;
        pos = hots[i] - d;
        for(int j = 0; j < n; j++)
        {
            if(abs(pos - hots[j]) < d) b = true;
        }
        if(b) continue;
        count++;
    }
    //cout << count << endl;
    for(int i = 0; i < n; i++)
    {
        b = false;
        pos = hots[i] + d;
        for(int j = 0; j < n; j++)
        {
           if(abs(pos - hots[j]) < d || (abs(pos - hots[j]) == d && j != i)) b = true;
        }
        if(b) continue;
        count++;
    }
    cout << count;
    return 0;
}