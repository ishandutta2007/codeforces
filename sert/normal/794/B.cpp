#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int main()
{
    //freopen("a.in", "r", stdin);
    int n, h;
    cin >> n >> h;

    for (int i = 1; i < n; i++) {
        printf("%.10f ", h * sqrt((i + 0.0) / (n + 0.0)));
    }

    return 0;
}