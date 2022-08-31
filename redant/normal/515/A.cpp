#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int a, b, s;

bool solve() {
    int r = abs(a) + abs(b);
    if (s < r) return false;
    return (s-r)%2 == 0;
}

int main() {
    setIO();
    cin>>a>>b>>s;
    cout<<(solve()?"Yes":"No")<<"\n";
    
    return 0;
}