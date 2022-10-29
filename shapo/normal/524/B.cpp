#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <omp.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector <ll> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

int n; 
int w[1111], h[1111]; 

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int n; 
    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i]; 
    }

    int ans = 1e9; 

    for (int H = 0; H <= 1111; H++) {
        bool ok = 1; 
        int sumw = 0; 
        for (int i = 0; i < n; i++) {
            if (w[i] <= H && h[i] <= H) {
                sumw += min(w[i], h[i]); 
            } else if (min(w[i], h[i]) <= H) {
                sumw += max(w[i], h[i]); 
            } else {
                ok = 0; 
            }
        }
        if (ok) {
            ans = min(ans, H * sumw); 
        }
    }

    cout << ans << "\n"; 

    return 0;
}