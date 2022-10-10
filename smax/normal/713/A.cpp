#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, query[1<<18] = {0};
    cin >> n;
    for (int i=0; i<n; i++) {
        char c;
        long long a;
        cin >> c >> a;
        if (c == '?') {
            int dec = 0, pos = 0;
            while (a > 0) {
                if (a % 10 == 1)
                    dec |= 1 << pos;
                a /= 10;
                pos++;
            }
            cout << query[dec] << endl;
        }
        else {
            int bin = 0, pos = 0;
            while (a > 0) {
                if (a % 10 % 2 == 1)
                    bin |= 1 << pos;
                a /= 10;
                pos++;
            }
            if (c == '+')
                query[bin]++;
            else
                query[bin]--;
        }
    }
    
    return 0;
}