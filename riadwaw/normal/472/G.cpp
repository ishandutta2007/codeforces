/**
 * BE CAREFUL!! I have define int li sometimes
 */

//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>
#include <numeric>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
//typedef pair<int, int> pi;

void solve();

void prec();


#define FILENAME "souvenir"

int main() {
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("/Users/RiaD/Contests/Contests/output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    //prec();
    int tests = 1;
    //cin >> tests;

    while (tests--) {
        solve();
    }
#ifdef DEBUG
    //cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}
unsigned long long shifted1[64][200000/64];
unsigned long long shifted2[64][200000/64];
char s[2000000];
char* ptr = s;
inline int parse() {
    int ans = 0;
    while(*ptr != 0 && *ptr != ' ') {
        ans = ans * 10 + *ptr - '0';
        ++ptr;
    }
    ++ptr;
    return ans;
}

int cnt[1<<16];
void solve() {

    for(int i = 0; i < (1 << 16); ++i) {
        for(int j = 0; j < 16; ++j) {
            cnt[i] += ((i >> j) & 1);
        }
    }
    gets(s);
    for(int i = 0; s[i]; ++i) {

        if(s[i] == '1') {
            for (int j = 0; j < 64; ++j) {
                if (i >= j) {
                    shifted1[j][(i - j) >> 6] |= (1ULL << ((i - j) & 63));
                }
            }
        }
    }

    gets(s);
    for(int i = 0; s[i]; ++i) {
        if(s[i] == '1') {
            for (int j = 0; j < 64; ++j) {
                if (i >= j) {
                    shifted2[j][(i - j) >> 6] |= (1ULL << ((i - j) & 63));
                }
            }
        }
    }

    gets(s);
    int q = parse();
    unsigned long long last16 = (1 << 16) - 1;
    while(q--) {
        gets(s);
        ptr = s;
        int ans = 0;
        int p1 = parse();
        int p2 = parse();
        int len = parse();
        unsigned long long* ptr1 = shifted1[p1 & 63] + (p1 >> 6);
        unsigned long long* ptr2 = shifted2[p2 & 63] + (p2 >> 6);
        int r = len >> 6;

        for (int i = 0; i < r; ++i) {
            unsigned long long cur = *ptr1 ^*ptr2;
            ++ptr1;
            ++ptr2;
            ans += cnt[cur >> 48] + cnt[(cur >> 32) & (last16)] + cnt[(cur >> 16) & last16] + cnt[cur & last16];
        }
        unsigned long long cur = (*ptr1 ^ *ptr2) & ((1ULL << (len & 63)) - 1);
        //cout << *ptr1 << ' '<< *ptr2;
        ans += cnt[cur >> 48] + cnt[(cur >> 32) & (last16)] + cnt[(cur >> 16) & last16] + cnt[cur & last16];


        printf("%d\n", ans);
    }
}