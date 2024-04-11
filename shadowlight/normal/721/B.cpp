#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> data(101, 0);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s.size();
        data[x]++;
    }
    string s1;
    cin >> s1;
    int m = s1.size();
    int sum = 0;
    for (int i = 1; i < m; i++) {
        sum += data[i];
    }
    int sum1 = sum;
    int sum2 = sum + data[m] - 1;
    cout << sum1 + sum1 / k * 5 + 1 << " ";
    cout << sum2 + sum2 / k * 5 + 1;
}