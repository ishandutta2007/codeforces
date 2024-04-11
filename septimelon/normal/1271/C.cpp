#include <bits/stdc++.h>

using namespace std;

struct coor {
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    coor s;
    cin >> n >> s.x >> s.y;
    vector<coor> p(n);
    vector<int> coun(4, 0);
    vector<coor> dir({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        if (p[i].x > s.x) {
            ++coun[0];
        }
        if (p[i].y > s.y) {
            ++coun[1];
        }
        if (p[i].x < s.x) {
            ++coun[2];
        }
        if (p[i].y < s.y) {
            ++coun[3];
        }
    }
    int mi = 0;
    for (int i = 1; i < 4; ++i) {
        if (coun[i] > coun[mi]) {
            mi = i;
        }
    }
    cout << coun[mi] << '\n';
    cout << s.x + dir[mi].x << " " << s.y + dir[mi].y << '\n';
    return 0;
}