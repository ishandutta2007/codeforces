#include <bits/stdc++.h>
using namespace std;

char grid[1000][1000];
int x, mh;

void drawl(int sz) {
    mh = max(mh, sz);
    for(int y = 500 - sz; y <= 500 + sz; y++)
        grid[y][x] = '|';
    grid[500 - sz][x] = '+';
    grid[500 + sz][x] = '+';
    grid[500 - sz][x-1] = '-';
    grid[500 + sz][x-1] = '-';
}

void drawr(int sz) {
    mh = max(mh, sz);
    for(int y = 500 - sz; y <= 500 + sz; y++)
        grid[y][x] = '|';
    grid[500 - sz][x] = '+';
    grid[500 + sz][x] = '+';
    grid[500 - sz][x+1] = '-';
    grid[500 + sz][x+1] = '-';
}


int main() {
    for(int i = 0; i < 1000; i++)
        fill(grid[i], grid[i] + 1000, ' ');
    x = 0;
    int n;
    string s;
    cin >> n >> s;
    int cu = 0, mx = 0;
    for(auto c : s) {
        cu += c == '[';
        cu -= c == ']';
        mx = max(mx, cu);
    }
    cu = 0;
    for(int i = 0; i < n; i++) {
        x++;
        if(s[i] == '[') {
            cu++;
            drawr(mx - cu + 1);
        }
        else {
            if(s[i - 1] == '[')
                x += 3;
            cu--;
        }
    }
    int br = x;
    x++;
    cu = 0;
    for(int i = n - 1; i >= 0; i--) {
        x--;
        if(s[i] == ']') {
            cu++;
            drawl(mx - cu + 1);
        }
        else {
            if(s[i + 1] == ']')
                x -= 3;
            cu--;
        }
    }
    for(int y = 500 - mh; y <= 500 + mh; y++) {
        for(int o = 1; o <= br; o++)
            cout << grid[y][o];
        cout << '\n';
    }
}