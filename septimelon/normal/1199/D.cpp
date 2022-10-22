#include <bits/stdc++.h>

using namespace std;

struct hap {
    int type;
    int x;
    int p;
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<hap> haps;
    int q;
    cin >> q;
    hap h1;
    for (int i = 0; i < q; i++) {
        cin >> h1.type;
        if (h1.type == 1)
            cin >> h1.p;
        cin >> h1.x;
        haps.push(h1);
    }
    stack<hap> balc;
    int maxvip = 0;
    while (!haps.empty()) {
        h1 = haps.top();
        haps.pop();
        if (h1.type == 1) {
            h1.x = max(h1.x, maxvip);
            balc.push(h1);
        }
        else {
            maxvip = max(maxvip, h1.x);
        }
    }
    for (int i = 0; i < n; i++)
        a[i] = max(a[i], maxvip);
    while (!balc.empty()) {
        a[balc.top().p-1] = balc.top().x;
        balc.pop();
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}