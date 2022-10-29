#include <iostream>
#include <cstdio>

using namespace std;

const int MAXC = 55;
const int MAXW = 42;

// all global variables
// initialized by zeros
char field[MAXC][MAXC];

int
main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    char colors[] = "ABCD";
    // fill big squares
    //
    // AAAAABBBBB
    // AAAAABBBBB
    // AAAAABBBBB
    // AAAAABBBBB
    // AAAAABBBBB
    // CCCCCDDDDD
    // CCCCCDDDDD
    // CCCCCDDDDD
    // CCCCCDDDDD
    // CCCCCDDDDD
    // (in example 5x5, actually 21x21)
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            char color = colors[i * 2 + j];
            for (int r = 0; r < MAXW / 2; ++r) {
                for (int c = 0; c < MAXW / 2; ++c) {
                    field[i * MAXW / 2 + r][j * MAXW / 2 + c] = color;
                }
            }
        }
    }
    // Make isolated components of colors
    // in next order squares
    // (i.e. A -> B, B -> C, C -> D, D -> A
    int cnt[4] = {a - 1, b - 1, c - 1, d - 1};
    for (int color_id = 0; color_id < 4; ++color_id) {
        int next_color_id = (color_id + 1) % 4;
        int i = next_color_id / 2, j = next_color_id % 2;
        int start_r = i * (MAXW / 2), start_c = j * (MAXW / 2);
        for (int idx = 0; idx < cnt[color_id]; ++idx) {
            int row_id = idx / (MAXW / 4), col_id = idx % (MAXW / 4);
            field[start_r + row_id * 2 + 1][start_c + col_id * 2 + 1] = colors[color_id];
        }
    }
    cout << MAXW << ' ' << MAXW << endl;
    for (int i = 0; i < MAXW; ++i) {
        cout << field[i] << endl;
    }
    return 0;
}