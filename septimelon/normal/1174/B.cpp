#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v1;
    int n;
    cin >> n;
    int a;
    bool ch = false;
    bool nech = false;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) ch = true;
        else nech = true;
        v1.push_back(a);
    }
    if (ch && nech)
        sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++)
        cout << v1[i] << " ";
    return 0;
}