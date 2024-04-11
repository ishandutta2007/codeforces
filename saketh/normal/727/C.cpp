#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int s12, s23, s13;

    cout << "? 1 2" << endl;
    cin >> s12;
    cout << "? 2 3" << endl;
    cin >> s23;
    cout << "? 1 3" << endl;
    cin >> s13;

    int res[N];

    res[0] = (s12 + s13 - s23) / 2;
    res[1] = s12 - res[0];
    res[2] = s13 - res[0];

    for (int i = 3; i < N; i++) {
        cout << "? 1 " << i + 1 << endl;
        int s;
        cin >> s;
        res[i] = s - res[0];
    }

    cout << "!";
    for (int i = 0; i < N; i++) {
        cout << " " << res[i];
    }
    cout << endl;

    return 0;
}