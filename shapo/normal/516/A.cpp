#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
    int n;
    vector< int > cnt(10);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        int x = c - '0';
        if (x == 0 || x == 1) {
            continue;
        } else if (x == 2 || x == 3 || x == 5 || x == 7) {
            cnt[x]++;
        } else if (x == 4) {
            cnt[3]++;
            cnt[2] += 2;
        } else if (x == 6) {
            cnt[5]++;
            cnt[3]++;
        } else if (x == 8) {
            cnt[7]++;
            cnt[2] += 3;
        } else if (x == 9) {
            cnt[7]++;
            cnt[2] += 1;
            cnt[3] += 2;
        }
    }
    for (int i = 9; i > 1; --i) {
        while (cnt[i]) {
            --cnt[i];
            cout << char(i + '0');
        }
    }
    cout << endl;
    return 0;
}