#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef int_fast64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}



int main() {
    start();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (input<int>() == 1) {
            cout << "HARD" << endl;
            return 0;
        }
    }
    cout << "EASY" << endl;

    return 0;
}