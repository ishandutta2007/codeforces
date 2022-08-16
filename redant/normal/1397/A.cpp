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
        int f[26]={0};
        int n; cin>>n;
        for (int i = 0; i < n; i++) {
            string s; cin>>s;
            for (int j = 0; j < s.size(); j++)
                f[s[j]-'a']++;
        }
        bool ok = true;
        for (int i = 0; i < 26 && ok; i++)
            ok = (f[i]%n == 0);
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}