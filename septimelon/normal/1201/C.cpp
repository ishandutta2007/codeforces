#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a.push_back(9999999999);
    sort(a.begin(), a.end());
    int ind = (n-1)/2;
    ll delta = 0;
    ll len = 1;
    ll med = a[ind];
    while (a[ind+1] == a[ind]) {
        len++;
        ind++;
    }
    delta = a[ind+1] - a[ind];
    while (k >= delta * len) {
        med += delta;
        k -= (delta * len);
        a[ind] = a[ind+1];
        while (a[ind+1] == a[ind]) {
            len++;
            ind++;
        }
        delta = a[ind+1] - a[ind];
    }
    med += k/len;
    cout << med << endl;
    return 0;
}