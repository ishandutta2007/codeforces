#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 100008;


int main() {
    long long n;
    cin >> n;
    vector <pair <long long, double> > data;
    vector <pair <long long, long long> >dots;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        dots.push_back({x, y});
        for (long long j = 0; j < i; j++) {
            long long x1 = dots[j].first, y1 = dots[j].second;
            long long rast = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
            double coef;
            if (x == x1) coef = INF; else coef = (double) (y - y1) / (x - x1);
            data.push_back({rast, coef});
           // cout << rast << " " << coef << endl;
        }
    }
    sort(data.begin(), data.end());
    long long ans = 0;
    long long size = 0;
    for (int i = 1; i < data.size(); i++) {
        if (data[i].first == data[i - 1].first && data[i - 1].second == data[i].second) size++; else {
           // if (size != 0) cout << size << endl;
            ans += size * (size + 1) / 2;
            size = 0;
        }
    }
    //if (size != 0) cout << size << endl;
    ans += (size + 1) * size / 2;
    ans /= 2;
    cout << ans << endl;
}