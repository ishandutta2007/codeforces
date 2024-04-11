#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int A[MAXN], B[MAXN];
int T[MAXN];

void gogo (int x)
{
    T[0] = x;
    for (int i = 1; i < N; i++)
        T[i] = A[i-1] + B[i-1] - T[i-1];

    for (int i = 0; i < N - 1; i++)
        if ((T[i] | T[i+1]) != A[i] || (T[i] & T[i+1]) != B[i])
            return;
    cout << "YES\n";
    for (int i = 0; i < N; i++)
        cout << T[i] << " ";
    cout << "\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
        cin >> A[i];
    for (int i = 0; i < N - 1; i++)
        cin >> B[i];

    for (int i = 0; i < 4; i++)
        gogo (i);
    cout << "NO\n";
    return 0;
}