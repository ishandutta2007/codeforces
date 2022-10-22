#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v1;
    int n;
    cin >> n;
    n *= 2;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());
    if (v1[0] == v1[n-1]) {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << v1[i] << " ";
    return 0;
}