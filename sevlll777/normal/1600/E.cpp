#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void kek(bool x) {
  if (x) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> R(n), L(n);
  for (int i = n - 2; i >= 0; i--) {
    if (A[i] < A[i + 1]) {
      R[i] = R[i + 1] + 1;
    }
  }
  for (int i = 1; i < n; i++) {
    if (A[i] < A[i - 1]) {
      L[i] = L[i - 1] + 1;
    }
  }
  int l = 0, r = n - 1, last = -1;
  bool alc = true;
  while (true) {
    if (l > r || (A[l] <= last && A[r] <= last)) {
      kek(!alc);
      break;
    }
    if (l != r) {
      if (A[l] > A[r]) {
        if (R[l] % 2 == 0) {
          kek(alc);
          break;
        } else {
          if (A[r] > last) {
            last = A[r];
            r--;
          } else {
            kek(!alc);
            break;
          }
        }
      } else if (A[l] < A[r]) {
        if (L[r] % 2 == 0) {
          kek(alc);
          break;
        } else {
          if (A[l] > last) {
            last = A[l];
            l++;
          } else {
            kek(!alc);
            break;
          }
        }
      } else {
        if (L[r] % 2 == 0 || R[l] % 2 == 0) {
          kek(alc);
        } else {
          kek(!alc);
        }
        break;
      }
    } else {
      kek(alc);
      break;
    }
    alc = !alc;
  }

}