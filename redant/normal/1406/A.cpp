#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 105;
int n, m;
int a[SZ];
int f[SZ];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < SZ; i++) f[i] = 0;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            f[a[i]]++;
        }
        int r = 0;
        bool got = false;
        for (int i = 0; i < SZ; i++) {
            if (f[i]>1) {
                continue;
            }
            if (!got) {
                if(f[i]==0) {
                    r = 2*i;
                    break;
                } else {
                    r = i;
                }
                got = true;
            } else {
                if(f[i]==0) {
                    r += i;
                    break;
                }
            }
        }
        cout<<r<<endl;
    }
    
    return 0;
}