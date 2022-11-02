#include <bits/stdc++.h>

using namespace std;

using INT = long long ;

int solve(INT n) {
    int c=0;
    INT p=n;
    for(int i=2; (INT)i*i<=n; i++) if(n%i==0) {
        while(n%i==0) n/=i;
        c++;
        p=i;
    }
    if(n>1) p=n, c++;
    if(c<=1) cout << p << endl;
    else cout << 1 << endl;

}

int main() {
    INT n;
    cin >> n;
    solve(n);
}