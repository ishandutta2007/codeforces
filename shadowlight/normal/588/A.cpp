#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n, m, allcount = 0;
    cin >> n;
    vector <int> count(n, 0), mas(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> mas[i] >> count[i];
    }
    int i = 0;
    while (i < n) {
        allcount += count[i] * mas[i];
        int t = count[i];
        while (t < count[i + 1] && i + 1< n) {
            allcount += t * mas[i + 1];
            i++;
        }
        i++;
    }
    cout << allcount;

}