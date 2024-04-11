#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
   long long n, m;
    cin >> n >> m;
    vector <int> data(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    int it1 = 0;
    int maxc = 0, num = m;
    int it2 = 0;
    while (it2 < n && num != 0) {
        if (!data[it2]) num--;
        it2++;
    }
    while (it2 < n && data[it2]) it2++;
    maxc = it2 - it1;
    int l = 0, r = it2 - 1, it = 0;
    while (data[it]) it++;
    while (it2 < n) {
        it1 = it + 1;
        it++;
        while (it < n && data[it]) {
            it++;
        }
        while (it2 < n && data[it2]) {
            it2++;
        }
        it2++;
        while (it2 < n && data[it2]) {
            it2++;
        }
        if (it2 - it1 > maxc) {
            maxc = it2 - it1;
            l = it1;
            r = it2 - 1;
        }
        //cout << maxc << endl;
    }
    cout << maxc << endl;
    for (int i = l; i <= r; i++) {
        data[i] = 1;
    }
    for (int i = 0; i < n ; i++) cout << data[i] << " ";
    //return 0;
}