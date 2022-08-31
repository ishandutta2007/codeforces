#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n;
int a[SZ];
int b[SZ];

bool solve() {
    int diff = -1; 
    int p = 0;
    for (; p < n; p++) {
        if (a[p] != b[p]) 
            break;
    }
    if (p == n) return true;
    if (a[p] > b[p]) return false;
    diff = b[p] - a[p];
    while (p < n && (b[p] - a[p]) == diff)
        p++;
    for (; p < n; p++) {
        if (a[p] != b[p]) 
            return false;
    }
    return true;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}