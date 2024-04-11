#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_uniqe(int* a, int n) {
    int c[10000] = {0};

    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ss";
        c[a[i]]++;
        if (c[i] > 1) {
            return false;
        }
    }

    for (int i = 0; i < 10000; i++) {
        if (c[i] > 1) {
            return false;
        }
    }

    return true;
}

bool k(int a, int b) {
    return b < a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* a = new int[n];
        int* b = new int[n];
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }

        sort(a, a + n, k);
        for (int i = 0; i < n; i++)  {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}