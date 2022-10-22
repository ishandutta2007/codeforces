#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    int n, t, curm;
    int buf;
    cin >> t;
    for (int qq = 0; qq < t; qq++) {
        cin >> n;
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> buf;
            a.push_back(buf);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        curm = a[1];
        curm--;
        //cout << curm << "-";
        cout << min(curm, n-2) << endl;
    }
    return 0;
}