#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    
    cout << ((n % (2 * k + 1) == 0) ? n / (2 * k + 1) : n / (2 * k + 1) + 1) << endl;
    if (n % (2 * k + 1) == 0)
        for (int i=k+1; i<=n; i+=2*k+1)
            cout << i << " ";
    else {
        if (n % (2 * k + 1) > k)
            for (int i=n%(2*k+1)-k; i<=n; i+=2*k+1)
                cout << i << " ";
        else
            for (int i=1; i<=n; i+=2*k+1)
                cout << i << " ";
    }
    cout << endl;
    
    return 0;
}