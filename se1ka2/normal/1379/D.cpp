#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 100000000;

int main()
{
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    m /= 2;
    int a[100005];
    int c[100005];
    for(int i = 0; i < n; i++){
        int b;
        cin >> b >> a[i];
        a[i] %= m;
        c[i] = a[i];
    }
    sort(a, a + n);
    int al = -1;
    int l = INF;
    for(int i = 0; i < n; i++){
        int d = upper_bound(a, a + n, (a[i] + m - k) % m) - a;
        if((i + n - d) % n < l){
            l = (i + n - d) % n;
            al = i;
        }
    }
    int t = a[al];
    cout << l << " " << t << endl;
    for(int i = 0; i < n; i++){
        if((t + m - c[i]) % m < k && (t + m - c[i]) % m != 0) cout << i + 1 << " ";
    }
    cout << endl;
}