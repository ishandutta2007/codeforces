#include <iostream>
using namespace std;
long long n, res, a[1005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=2; i<=n; i+=2) {
        long long sum = 1;
        long long high = a[i] - 1;
        for(int j=i-1; j>0; j-=2) {
            res += max(0ll, min(a[j] - sum, high) + 1);
            sum -= a[j];
            if (sum < 0) {
                high += sum;
                sum = 0;
            }
            sum += a[j-1];

            if (high < 0) break;
        }
    }
    cout << res;
}