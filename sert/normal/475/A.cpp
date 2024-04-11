#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
string s[10];
int n;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    for (int i = 0; i < 27; i++)
        for (int j = 0; j <= 5; j++)
            if (n != 0 && s[j][i] == '#') {
                s[j][i] = 'O';
                n--;
            }
    for (int i = 0; i <= 5; i++)
        cout << s[i] << "\n";
    return 0;
}