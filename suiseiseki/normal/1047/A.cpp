#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    long long n;
    bool pd = 0;
    cin >> n;

    for(long long i = 1; i < n; i++) {
        for(long long j = 1; j < n; j++) {
            if(((n - i - j) % 3) != 0 && (i % 3) != 0 && (j % 3) != 0) {
                cout << i << " " << j << " " << (n - i - j);
                pd = true;
                break;
            }
        }

        if(pd) {
            break;
        }
    }

    return 0;
}