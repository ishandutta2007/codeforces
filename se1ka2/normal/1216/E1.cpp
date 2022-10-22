#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll a[1000000];
ll h[1000000];

int main()
{
    ll now = 0;
    ll b = 0;
    for(int i = 1; i < 1000000; i++){
        if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) b++;
        now += b;
        a[i] = a[i - 1] + now;
    }
    b = 0;
    for(int i = 1; i < 1000000; i++){
        if(i == 1 || i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) b++;
        h[i] = h[i - 1] + b;
    }
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int k;
        cin >> k;
        int d = lower_bound(a, a + 1000000, k) - a;
        int l = k - a[d - 1];
        int e = lower_bound(h, h + 1000000, l) - h;
        int f = h[e] - l;
        for(int i = 0; i < f; i++) e /= 10;
        cout << e % 10 << endl;
    }
}