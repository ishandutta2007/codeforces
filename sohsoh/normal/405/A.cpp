#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> clms;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        clms.push_back(t);
    }

    sort(clms.begin(), clms.end());

    for (int i = 0; i < clms.size(); i++) {
        cout << clms[i] << " ";
    }

    return 0;
}