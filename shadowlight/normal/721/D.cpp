#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;

const long long INF = 1e9 + 7;
int main() {
    long long n, k, x;
    cin >> n >> k >> x;
    vector <long long> data(n, 0);
    long long mink = INF;
    long long pos;
    long long cnt = 0;
    vector <long long> change(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> data[i];
        if (data[i] < 0) {
            cnt++;
            change[i] = 1;
            data[i] = -data[i];
        }
        if (mink > data[i]) {
            mink = data[i];
            pos = i;
        }
    }
    for (long long i = 0; i < n; i++) {
        if (data[i] == 0 && k != 0) {
            data[i] += x;
            k--;
            if (cnt % 2 == 0) {
                cnt++;
                change[i] = 1;
            }
        }
    }
    if (cnt % 2 == 0) {
        if (mink >= k * x) {
            data[pos] -= k * x;
            for (long long i = 0; i < n; i++) {
                if (change[i]) data[i] = -data[i];
                cout << data[i] << " ";
            }
            return 0;
        } else {
            long long l = data[pos] / x;
            if (l * x <= data[pos]) l++;
            k -= l;
            data[pos] -= l * x;
            data[pos] = -data[pos];
            change[pos] ^= 1;
        }
    }
    set <pair <long long, long long> > s;
    for (long long i = 0; i < n; i++) {
        s.insert({data[i], i});
    }
    for (long long j = 0; j < k; j++) {
        long long v = (*s.begin()).second;
        s.erase({data[v], v});
        data[v] += x;
        s.insert({data[v], v});
    }
    for (long long i = 0; i < n; i++) {
        if (change[i]) data[i] = -data[i];
        cout << data[i] << " ";
    }
}