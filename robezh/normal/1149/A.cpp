#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
int cnt1 = 0, cnt2 = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 1) cnt1 ++;
        else cnt2 ++;
    }
    if(cnt1 == 0) {
        for(int j = 0; j < n; j++) cout << 2 << " ";
        return 0;
    }
    if(cnt2 == 0) {
        for(int j = 0; j < n; j++) cout << 1 << " ";
        return 0;
    }
    cout << "2 1 ";
    for(int i = 0; i < cnt2 - 1; i++) cout << 2 << " ";
    for(int i = 0; i < cnt1 - 1; i++) cout << 1 << " ";
    return 0;

}