#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, res = 0;
    int s;
    cin >> n;
    vector<int> speed;
    speed.push_back(1000);
    vector<bool> obgon;
    obgon.push_back(true);

    for (int i = 0; i < n; ++i) {
        int action;
        cin >> action;
        switch (action) {
        case 1:
            cin >> s;
            while (speed.back() < s) {
                speed.pop_back();
                ++res;
            }
            break;
        case 2:
            while (!obgon.back()) {
                obgon.pop_back();
                ++res;
            }
            break;
        case 3:
            int new_speed;
            cin >> new_speed;
            if (s > new_speed) {
                ++res;
            } else {
                speed.push_back(new_speed);
            }
            break;
        case 4:
            obgon.push_back(true);
            break;
        case 5:
            speed.push_back(1000);
            break;
        case 6:
            obgon.push_back(false);
            break;
        }
    }

    cout << res;
    return 0;
}