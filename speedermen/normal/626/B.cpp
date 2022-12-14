#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

inline void add(int &a, int b) {
    a += b;
    if (a >= MD) a -= MD;
}

int mem[222][222][222];

int f(int r, int g, int b) {
    if (mem[r][g][b] != -1) {
        return mem[r][g][b];
    }
    mem[r][g][b] = 0;
    if (r + g + b == 1) {
        if (r == 1)
            mem[r][g][b] = 1;
        else if (g == 1)
            mem[r][g][b] = 2;
        else
            mem[r][g][b] = 4;
        return mem[r][g][b];
    }
    if (r >= 2) {
        mem[r][g][b] |= f(r - 1, g, b);
    }
    if (g >= 2) {
        mem[r][g][b] |= f(r, g - 1, b);
    }
    if (b >= 2) {
        mem[r][g][b] |= f(r, g, b - 1);
    }
    if (r >= 1 && g >= 1) {
        mem[r][g][b] |= f(r - 1, g - 1, b + 1);
    }
    if (r >= 1 && b >= 1) {
        mem[r][g][b] |= f(r - 1, g + 1, b - 1);
    }
    if (g >= 1 && b >= 1) {
        mem[r][g][b] |= f(r + 1, g - 1, b - 1);
    }
    return mem[r][g][b];
}

int main()
{
    string s;
    int n;
    cin >> n >> s;
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < s.size(); ++i)
    if (s[i] == 'R') {
        r++;
    } else if (s[i] == 'G') {
        g++;
    } else {
        b++;
    }
    memset(mem, -1, sizeof(mem));
    int res = f(r, g, b);
    if (res & 4)
        cout << 'B';
    if (res & 2)
        cout << 'G';
    if (res & 1)
        cout << 'R';
    return 0;
}