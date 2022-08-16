#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
string s;
int n, k;
char a[SZ];

bool solve() {
    for (int i = 0; i <= k; i++)
        a[i] = '.';
    for (int i = 0; i < n; i++) {
        int p = i%k;
        if (s[i]!='?') {
            if (a[p]=='.') a[p]=s[i];
            else if(a[p]!=s[i]) return false;
        } else if(a[i]!='.') {
            s[i]=a[i];
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < k; i++) {
        x+=a[i]=='0';
        y+=a[i]=='1';
    }

    return (2*x<=k && 2*y<=k);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        cin>>s;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}