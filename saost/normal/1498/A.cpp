#include <iostream>
#include <algorithm>
using namespace std;
long long t, n;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        do {
            long long x = n, sum = 0;
            while (x) sum += x%10, x/=10;
            if (__gcd(n,sum) > 1) break;
            ++n;
        } while (true);
        cout << n << '\n';
    }
}