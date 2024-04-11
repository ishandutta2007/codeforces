#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 10500;
const int MAXK = 32;

int x[MAXN], y[MAXN];
int tmpx[MAXN], tmpy[MAXN];
int n;
vector< pair< int, int > > st, rev;
int coeff[MAXK][MAXK];

void my_swap(int *arr, int i, int j, vector< pair< int, int > > &write)
{
    if (i != j) {
        write.push_back(make_pair(i, j));
        arr[i] ^= arr[j];
        write.push_back(make_pair(j, i));
        arr[j] ^= arr[i];
        write.push_back(make_pair(i, j));
        arr[i] ^= arr[j];
    }
}

void
gauss(int *arr, vector< pair< int, int > > &write)
{
    int cnt = 0;
    while (true) {
        int ind = cnt;
        for (int i = cnt; i < n; ++i) {
            if (arr[i] > arr[ind]) {
                ind = i;
            }
        }
        if (ind >= n || arr[ind] == 0) {
            break;
        }
        my_swap(arr, cnt, ind, write);
        int cur_bit = 29;
        while (((1 << cur_bit) & arr[cnt]) == 0) {
            --cur_bit;
        }
        for (int j = cnt + 1; j < n; ++j) {
            if (((1 << cur_bit) & arr[j]) != 0) {
                arr[j] ^= arr[cnt];
                write.push_back(make_pair(j, cnt));
            }
        }
        ++cnt;
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        tmpx[i] = x[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> y[j];
        tmpy[j] = y[j];
    }
    st.clear();
    rev.clear();
    gauss(x, st);
    gauss(y, rev);
    int k = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] != 0) {
            k = i + 1;
        }
        if (y[i] != 0) {
            l = i + 1;
        }
    }
    bool ok = true;
    for (int i = 0; i < l && ok; ++i) {
        int cur_num = y[i];
        for (int j = 0; j < k; ++j) {
            coeff[i][j] = 0;
            int cur_bit = 29;
            while (((1 << cur_bit) & x[j]) == 0) {
                --cur_bit;
            }
            if (((1 << cur_bit) & cur_num) != 0) {
                cur_num ^= x[j];
                coeff[i][j] = 1;
            }
        }
        if (cur_num != 0) {
            ok = false;
        }
    }
    if (!ok) {
        puts("-1");
    } else {
        for (int row = 0, col = 0; row < l && col < k; ) {
            int ind = row;
            while (ind < l && coeff[ind][col] == 0) {
                ++ind;
            }
            if (ind == l) {
                ++col;
                continue;
            }
            if (ind != row) {
                rev.push_back(make_pair(ind, row));
                rev.push_back(make_pair(row, ind));
                rev.push_back(make_pair(ind, row));
                for (int j = 0; j < k; ++j) {
                    swap(coeff[ind][j], coeff[row][j]);
                }
            }
            for (int j = row + 1; j < l; ++j) {
                if (coeff[j][col] == 1) {
                    rev.push_back(make_pair(j, row));
                    for (int id = 0; id < k; ++id) {
                        coeff[j][id] ^= coeff[row][id];
                    }
                }
            }
            ++col;
            ++row;
        }
        for (int xpos = 0; xpos < k; ++xpos) {
            for (int ypos = min(xpos, l) - 1; ypos >= 0; --ypos) {
                if (coeff[ypos][xpos]) {
                    st.push_back(make_pair(ypos, xpos));
                }
            }
            if (xpos >= l || coeff[xpos][xpos] == 0) {
                st.push_back(make_pair(xpos, xpos));
            }
        }
        cout << st.size() + rev.size() << '\n';
        for (auto mv : st) {
            cout << mv.first + 1 << " " << mv.second + 1 << '\n';
        }
        reverse(rev.begin(), rev.end());
        for (auto mv : rev) {
            cout << mv.first + 1 << " " << mv.second + 1 << '\n';
        }
        cout.flush();
        // checker
        for (auto mv : st) {
            tmpx[mv.first] ^= tmpx[mv.second];
        }
        for (auto mv : rev) {
            tmpx[mv.first] ^= tmpx[mv.second];
        }
        for (int i = 0; i < n; ++i) {
            assert(tmpx[i] == tmpy[i]);
        }
    }
    /*for (auto x : rev) {
        swap(x.first, x.second);
    }*/
    return 0;
}