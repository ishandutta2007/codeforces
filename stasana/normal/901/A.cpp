#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h;
    cin >> h;
    ++h;
    vector<int> a(h);
    int n = 0;
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
        n += a[i];
    }
    int id = 1;
    bool f = true;
    for (int i = 1; i < h; ++i) {
        if (a[i] > 1 && a[i - 1] > 1) {
            id = i;
        }
        if (a[i] != (1 << i)) {
            f = false;
        }
    }
    if ((f && h <= 3) || !(a[id] > 1 && a[id - 1] > 1)) {
        cout << "perfect";
        return 0;
    }
    vector<int> res;
    int qwer;
    for (int i = 0; i < h; ++i) {
        int index = res.size();
        for (int j = 0; j < a[i]; ++j) {
            res.push_back(index);
        }
        if (id == i) {
            qwer = res.size() - 1;
        }
    }
    cout << "ambiguous" << endl;
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    --res[qwer];
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}