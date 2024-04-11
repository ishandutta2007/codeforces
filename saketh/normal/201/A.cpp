#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sharp[100];
int two[100];
int one[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int i = 1; i < 100; i++) {
        if(i&1) {
            sharp[i] = (i * i + 1) / 2;
            one[i] = true;
            if(i > 1) two[i] = true;
        }
        else {
            int sub = i / 2 - 1;
            int his = (sub * sub + 1) / 2;
            sharp[i] = 4 * his; 
        }
    }
    
    int X;
    cin >> X;

    for (int i = 1; i < 100; i++) {
        if(sharp[i] < X) continue;

        int rem = X % 4;

        if((rem & 1) && !one[i]) continue;
        if((rem & 2) && !two[i]) continue;
        if((rem & 1) && (rem & 2) && (i == 3)) continue;

            cout << i << "\n";
            return 0;
    }
}