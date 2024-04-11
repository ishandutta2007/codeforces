#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[1010];
    vector<int> ind;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1) ind.push_back(i);
    }
    cout << ind.size() << endl;
    for(int i = 1; i < ind.size(); i++) cout << a[ind[i] - 1] << " ";
    cout << a[n - 1];
}