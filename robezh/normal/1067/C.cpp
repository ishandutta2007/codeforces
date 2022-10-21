#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n / 3; i++) cout << "3 " << i * 2 + 1<< endl;
    for(int i = 0; i < n - n / 3; i ++) cout << "0 " << i << endl;
}