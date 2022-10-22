#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 103;

int main() {
    int n;
    cin >> n;

    int suml = 0, sumr = 0;

    vector<int> b;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<int> a(k);

        for(int j = 0; j < k; j++)
            cin >> a[j];

        if(k % 2 == 0) {
            for(int j = 0; j < k / 2; j++)
                suml += a[j];
            for(int j = k / 2; j < k; j++)
                sumr += a[j];
        } else {
            for(int j = 0; j < k / 2; j++)
                suml += a[j];
            for(int j = k / 2 + 1; j < k; j++)
                sumr += a[j];

            b.push_back(a[k / 2]);
        }
    }

    sort(b.rbegin(), b.rend());

    for(int i = 0; i < b.size(); i++) {
        if(i % 2 == 0)
            suml += b[i];
        else
            sumr += b[i];
    }

    cout << suml << ' ' << sumr;
}