#include <algorithm>
#include <assert.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <utility>

#include <bitset>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define dbg(a)        cerr << #a << " = " << (a) << '\n'
#define dbg2(a, b)    cerr << #a << " = " << (a) << " " << #b << " = " << (b) << '\n'
#define dbg3(a, b, c) cerr << #a << " = " << (a) << " " << #b << " = " << (b) << " " << #c << " = " << (c) << '\n'

using std::cerr;
using std::cin;
using std::cout;

using std::bitset;
using std::deque;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

using std::abs;
using std::max;
using std::min;

using std::sort;
using std::swap;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<ushort, ushort> pus;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pul;


void init() {
    std::iostream::sync_with_stdio(0);
    cout << std::fixed;
    cout.precision(10);
    cerr << std::fixed;
    cerr.precision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}
int gcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    } 
    return a;
}

pair<int, string> solve(vector<int> arr) {
    int oddcnt = 0;
    for (auto i : arr) 
        oddcnt += i % 2;
    if (oddcnt == 0) {
        int g = 0;
        for (auto i : arr)
            g = gcd(g, i);
        for (auto &i : arr)
            i /= g;
        string ans = "", part = "", revpart;
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < arr[i]; ++j)
                part += ('a' + i);
        revpart = part;
        std::reverse(revpart.begin(), revpart.end());
        for (int i = 0; i < g; i += 2) 
            ans += part + revpart;
        return {g, ans};
    } else if (oddcnt == 1) {
        int where = -1;
        for (int i = 0; i < 26; ++i)
            if (arr[i] % 2)
                where = i;

        int g = 0;
        for (auto i : arr)
            g = gcd(g, i);
        for (auto &i : arr)
            i /= g;

        string part = "", ans = "";
        for (int i = 0; i < 26; ++i)
            if (i != where)
                for (int j = 0; j < arr[i] / 2; ++j)
                    part += ('a' + i);
        for (int j = 0; j < arr[where]; ++j)
            part += ('a' + where);
        for (int i = 25; i >= 0; --i)
            if (i != where)
                for (int j = 0; j < arr[i] / 2; ++j)
                    part += ('a' + i);

        for (int i = 0; i < g; ++i)
            ans += part;
        return {g, ans};
    } else {
        string ans = "";
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < arr[i]; ++j)
                ans += ('a' + i);
        return {0, ans};
    }
}

int main() {
    init();

    vector<int> arr(26, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    auto get = solve(arr);
    cout << get.ff << '\n' << get.ss << '\n';
    
       
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}