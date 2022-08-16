// https://codeforces.com/contest/1392/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int a; cin>>a;
        bool same = true;
        for (int i = 1; i < n; i++) {
            int b; cin>>b;
            if (a != b) same = false;
        }
        cout<<(same?n:1)<<"\n";
    }
    return 0;
}