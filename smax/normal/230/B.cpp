#include <bits/stdc++.h>
using namespace std;
 
bool prime[1000001];
 
void sieve(int n) {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p=2; p*p<=n; p++)
        if (prime[p])
            for (int i=p*p; i<=n; i+=p)
                prime[i] = false;
}
 
int main() {
    int n;
    sieve(1000000);
    cin >> n;
    for (int i=0; i<n; i++) {
        long long x;
        cin >> x;
        int sq = (int)(sqrt(x)+0.5);
        if ((long long)sq * (long long)sq == x && prime[sq])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}