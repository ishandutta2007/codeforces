#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

char s[][100] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int main() {
    //freopen("~input.txt" , "r" , stdin);

    int K , i , j;
    cin >> K;
    for (i = 0 ; i < 100 ; ++ i)
        for (j = 0 ; j < 6 ; ++ j)
            if (K && s[j][i] == '#') {
                s[j][i] = 'O';
                -- K;
            }
    for (i = 0 ; i < 6 ; ++ i)
        puts(s[i]);

    return 0;
}