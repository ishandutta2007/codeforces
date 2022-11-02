#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[100010];
LL wq[2000010];

int main(){

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int g = __gcd(x, y);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    x /= g;
    y /= g;
    // swap(x, y);
    int s = x + y;
    int cnt = 0;
    for (int i = 1; i <= x; i++){
        wq[cnt++] = 1ll * i * y;
    }
    for (int i = 1; i <= y; i++){
        wq[cnt++] = 1ll * i * x;
    }
    sort(wq, wq + cnt);
    string A[3] = {"Both", "Vanya", "Vova"};
    for (int i = 0; i < n; i++){
        a[i]--;
        a[i] %= s;
        long long X = wq[a[i]];
        int ans = 0;
        if (X % x)
            ans |= 1;
        if (X % y)
            ans |= 2;
        cout << A[ans] << "\n";
    }

    return 0;
}