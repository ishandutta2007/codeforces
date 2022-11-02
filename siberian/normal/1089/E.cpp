#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string let = "abcdefgh";

vector<pair<int, int>> all;

void init() {
    int x = 0;
    int y = 0;
    for (int i = 0; i < 48; ++i) {
        all.push_back({ x, y });
        if (x % 2 == 0) {
            if (y < 7) {
                y++;
            } else {
                x++;
            }
            continue;
        }
        if (y > 0) {
            y--;
        } else {
            x++;
        }
    }
    for (int i = 48; i < 60; ++i) {
        all.push_back({ x, y });
        if (y % 2 == 0) {
            if (x < 7) {
                x++;
            }
            else {
                y++;
            }
            continue;
        }
        if (x > 6) {
            x--;
        }
        else {
            y++;
        }
    }
    //for (auto elem : all) {
    //    cout << elem.first << "/" << elem.second << "\n";
    //}

}

void print(vector<pair<int, int>> &ans) {
    for (auto elem : ans) {
        cout << (char)('a' + elem.first) << elem.second + 1 << " ";
    }
    cout << "\n";
}

int main() {
    init();
    int n;
    cin >> n;
    n += 1;
    vector<pair<int, int>> path;
    int x = 0;
    int y = 0;
    int now = 0;
    
    if (n <= 62) {
        int left = n;
        int pt = 0;
        while (left > 2) {
            path.push_back(all[pt]);
            x = all[pt].first;
            y = all[pt].second;
            pt++;
            left--;
        }
        if (x == 6) {
            path.push_back({ 6, 7 });
        } else if (x == 7) {
            path.push_back({ 7, 6 });
        } else if (y == 7) {
            path.push_back({ 6, 7 });
        } else {
            path.push_back({ 7, y });
        }
        path.push_back({7, 7});
    } else {
        if (n == 63) {
            path = all;
            path.push_back({ 6, 6 });
            path.push_back({ 6, 7 });
            path.push_back({ 7, 7 });
        }
        if (n == 64) {
            path = all;
            path.push_back({ 6, 7 });
            path.push_back({ 6, 6 });
            path.push_back({ 7, 6 });
            path.push_back({ 7, 7 });
        }
    }
    print(path);
}
//*/