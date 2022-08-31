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
    int a[102];
    while(t--) {
        int n; cin>>n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n);
        bool win = false;
        if (a[n-1]>(sum-a[n-1])) win=true;
        if(sum%2==1) win=true;
        cout<<(win?"T":"HL")<<"\n";
    }
    return 0;
}