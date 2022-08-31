#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, s;

LL getSum(LL n) {
    LL sum = 0;
    for (LL x = n; x; x/=10) sum += x%10;
    return sum;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        LL sum = getSum(n);
        LL p10 = 1;
        LL r = 0;
        while (sum > s) {
            LL d = 10-n%10;
            r += p10*d;
            n+=d;
            n/=10;
            sum=getSum(n);
            p10*=10;
        }
        cout<<r<<"\n";
    }
    
    return 0;
}