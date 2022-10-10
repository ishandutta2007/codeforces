#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> left;
    set<int> right;
    int count[100010];
    memset(count, 0, sizeof(count));
    vector<int> row;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        row.push_back(a);
        if(i > 0) right.insert(a);
        left.insert(a);
        if(i > 0) count[a]++;
    }
    long long tot = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int a;
        a = row[i];
        if(left.count(a))
        {
            left.erase(a);
            tot += right.size();
        }
        a = row[i + 1];
        //cout << i + 1 << " " << a << endl;
        count[a]--;
        //cout << count[1] << " " << count[2] << " " << count[3] << endl;
        if(count[a] == 0) right.erase(a);
        //cout << i << " " << tot << endl;
    }
    cout << tot;
}