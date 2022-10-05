#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long mod = 1000000007;
    long long n = 2*1000000;
    vector<long long> dpans(n,0);
    vector<long long> dp1(n,0);
    vector<long long> dp2(n,0);
    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        dp1[i] = (dp1[i-1] + dp2[i-1] * 2) % mod;
        dp2[i] = dp1[i-1];
        if(i>2) {dpans[i] = (dpans[i-3] + dp2[i-1] * 4) % mod;}
        else {dpans[i] = (dp2[i-1] * 4) % mod;}
    }
    int t;
    int k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k;
        cout << dpans[k-1] << endl;
    }
}