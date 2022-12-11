#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    int res = 0;
    cin >> n;
    string s;
    vector<int> a(n);
    ++n;
    for (int i = 1; i < n; ++i) {
        int j;
        cin >> j;
        s += to_string(i - res) + " ";
        --j;
        a[j] = 1;
        while (a.back() == 1) {
            a.pop_back();
            ++res;
        }
    }
    s += "1";
    cout << s;
    return 0;
}