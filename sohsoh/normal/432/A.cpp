#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int teamMembers = 0;
    int teams = 0;
    for (int i = 0; i < v.size(); i++) {
        if (5 - v[i] >= k) {
            teamMembers++;
        } else {
            break;
        }

        if (teamMembers >= 3) {
            teams++;
            teamMembers = 0;
        }
    }

    cout << teams << endl;
    return 0;
}