#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <pair <int, string> > > data(m + 1, vector <pair <int, string> > (2, {-1, " "}));
    vector <bool> nobody(m + 1, 0);
    for (int i = 0; i < n; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (b >= data[a][0].first) {
            if (data[a][0].first == data[a][1].first) {
                nobody[a] = 1;
            } else nobody[a] = 0;
            data[a][1].first = data[a][0].first;
            data[a][1].second = data[a][0].second;
            data[a][0].first = b;
            data[a][0].second = s;
        } else if (b >= data[a][1].first) {
            if (b == data[a][1].first)  nobody[a] = 1; else nobody[a] = 0;
            data[a][1].first = b;
            data[a][1].second = s;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!nobody[i] && data[i][0].first == data[i][1].first && data[i][0].second < data[i][1].second) swap(data[i][0], data[i][1]);
    if (nobody[i]) cout << "?" << endl; else cout << data[i][0].second << " " << data[i][1].second << endl;
    }
}