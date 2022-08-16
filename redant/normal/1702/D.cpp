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
    string s;
    int p;
    while(t--) {
        cin>>s>>p;
        vector<int> f(27, 0);
        int sum = 0;
        for (char c : s) {
            f[c-'a'+1]++;
            sum += c-'a'+1;
        }
        for (int i = 26; i > 0 && sum > p; i--) {
            int diff = sum - p;
            int c = min(f[i], ((diff+i-1)/i));
            sum -= c*i;
            f[i] -= c;
        }
        for (char c : s) {
            int i = c-'a'+1;
            if(f[i]) {
                cout<<c;
                f[i]--;
            }
        }
        cout<<"\n";
    }
    
    return 0;
}