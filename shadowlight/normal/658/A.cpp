#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int p[n], t[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int time = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        time += t[i];
        cnt1 += max(0, p[i] - c * time);
    }
    time = 0;
    int cnt2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        time += t[i];
        cnt2 += max(0, p[i] - c * time);
    }
    if (cnt1 > cnt2) {
        cout << "Limak" << endl;
    } else if (cnt1 == cnt2) {
        cout << "Tie" << endl;
    } else {
        cout << "Radewoosh" << endl;
    }
}