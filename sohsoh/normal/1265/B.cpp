#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<pair<int, int>> v;
        int a[50010] = {0};
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            v.push_back(make_pair(k, i + 1));
            a[k] = i + 1;
        }



        sort(v.begin(), v.end());
        int mn = v[0].second, mx = v[0].second;
        for (int j = 0; j < n; j++) {
            if (v[j].second > mx) {
                mx = v[j].second;
            }
            if (v[j].second < mn) {
                mn = v[j].second;
            }



            if (mx - mn == j) {
                cout << "1";
            } else {
                cout << "0";
            }
        }

        cout << endl;
    }
    return 0;
}