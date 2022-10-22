#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<char> v;

    for (int i = 0; i < n; i++) {
        char p;
        cin >> p;
        v.push_back(p);
    }

    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (v[i] == 'B' && v[i + 1] == 'G') {
                swap(v[i], v[i + 1]);
                i++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    return 0;
}