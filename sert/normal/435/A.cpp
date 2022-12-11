#include <iostream>

using namespace std;

const int N = 4e7;
const int X = 5;

bool get_bit(int mask, int x, int y) {
    if (mask == (mask | (1 << (y * X + x))))
        return true;
    return false;
}

int set_bits(int mask, int x, int y, int xx, int yy) {
    return mask | (1 << (y * X + x)) | (1 << (yy * X + xx));
}

bool u[N];
bool v[N];
int kol;

bool go(int mask) {
    bool win = false;
    if (u[mask])
        return v[mask];
    kol++;
    u[mask] = true;
    v[mask] = true;

    for (int i = 0; i < X; i++)
    for (int j = 0; j < X - 1; j++) {
        if (i == 1 && j == X - 2)
            continue;
        if (!get_bit(mask, j, i) && !get_bit(mask, j + 1, i))
            if (!go(set_bits(mask, j, i, j + 1, i)))
                win = true;
    }

    for (int i = 0; i < X - 1; i++)
    for (int j = 0; j < X; j++) {
        if (i < 2 && j == X - 1)
            continue;
        if (!get_bit(mask, j, i + 1) && !get_bit(mask, j, i))
            if (!go(set_bits(mask, j, i, j, i + 1)))
                win = true;
    }

    if (win)
        return true;

    return v[mask] = false;
}

int a[1000];
int ans = 1, t = 0;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (t + a[i] > m) {
            ans++;
            t = a[i];
        } else {
            t += a[i];
        }
    }

    cout << ans;

    return 0;
}