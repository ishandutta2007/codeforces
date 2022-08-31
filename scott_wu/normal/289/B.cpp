#include <iostream> // eugene
using namespace std; //scott
#include <algorithm>
int main() { int n, m, d; cin >> n >> m >> d; int a[105][105]; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j]; // eugene
bool bad = false; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((a[i][j] % d) != (a[n-1][m-1] % d)) bad = true; else a[i][j] /= d; // scott
if (bad) { cout << "-1\n"; return 0; } // eugene sex
int arr[100100]; for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) arr[i*m+j] = a[i][j]; sort (arr, arr + n * m); int sum = 0; for (int i = 0; i < n * m; i++) sum += ((arr[i] - arr[n*m/2] < 0) ? arr[n*m/2] - arr[i] : arr[i] - arr[n*m/2]); cout << sum << "\n"; return 0; // scott
} // eugene