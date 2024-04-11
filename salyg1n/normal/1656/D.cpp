//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <memory>
#include <iterator>
#include <ctime>
#include <cstdlib> 
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

//#define int ll
//#define DEBUG

using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int64_t n;
        cin >> n;
        int64_t n2 = n;
        int64_t y = 1;
        while(n%2 == 0)
        {
            y*=2;
            n/=2;
        }
        y*=2;
        if(y != 1 && y < int64_t(1e9) && y*(y+1)/2 <= n2)
        {
            cout << y << "\n";
        }
        else
        {
            int64_t y2 = n2*2/y;
            if(y2 == 1)
            {
                cout << -1 << "\n";
                continue;
            }
            if(y2*(y2+1)/2 <= n2)
            {
                cout << y2 << "\n";
            }
            else
                cout << -1 << "\n";
        }
    }
}