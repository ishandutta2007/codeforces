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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

int a[2][200][2000]; 
int n, T; 
int q[2000], t[2000], p[2000]; 

//
//int f(int i, int depth, int num) {
//  if (num == 0) return 0; 
//  if (i == n) {
//      return num == 0 ? 0 : -1000000000; 
//  }
//  if (num > n) {
//      return -1000000000; 
//  }
//  if (used[i][depth][num]) {
//      return mas[i][depth][num]; 
//  }
//  used[i][depth][num] = 1; 
//  int ans = f(i + 1, depth, num); 
//  ans = max(ans, f(i, depth + 1, 2 * num));
//
//  if (t[p[i]] + depth <= T) {
//      ans = max(ans, f(i + 1, depth, num - 1) + q[p[i]]); 
//  }
//  return mas[i][depth][num] = ans; 
//
//} 
//
bool cmp(int a, int b) {
    return t[a] > t[b] || (t[a] == t[b] && q[a] > q[b]); 
}

inline int getval(int i, int depth, int num) {
    if (num < 0) return -1000000000; 
    if (depth > T) return -1000000000;
    if (num == 0) return 0; 
    if (i == n) {
        return -1000000000; 
    }
    if (num > n) {
        return -1000000000; 
    }
    return a[i & 1][depth][num]; 
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    //ios::sync_with_stdio(false);

    //cerr << "here\n"; 
    
    cin >> n >> T; 
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> q[i];
        p[i] = i; 
    }

/*    n = 1000; T = 100; 
    for (int i = 0; i < 1000; i++) {
        t[i] = 1; 
        q[i] = rand(); 
    }
*/
    sort(p, p + n, cmp);

    for (int i = 0; i <= T; i++) {
        a[n & 1][i][0] = 0;
        for (int j = 1; j <= n; j++) {
            a[n & 1][i][j] = -1000000000; 
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int depth = T; depth >= 0; depth--) {
            for (int num = 0; num <= n; num++) {
                int ans = getval(i + 1, depth, num); 
                ans = max(ans, getval(i, depth + 1, 2 * num));
                
                if (t[p[i]] + depth <= T) {
                    ans = max(ans, getval(i + 1, depth, num - 1) + q[p[i]]); 
                }
                a[i & 1][depth][num] = ans; 
            }
        }
    }

    cout << a[0][0][1] << "\n"; 

    return 0;
}