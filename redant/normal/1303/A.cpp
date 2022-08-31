#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        string s; cin >> s;
        int left = 0, right = s.length() - 1;
        while(left < s.length() && s[left++] == '0'){}
        while(right >=0 && s[right--] == '0'){}
        int r = 0;
        for (int i = left; i <= right; i++)
            r += s[i] == '0';
        cout<<r<<"\n";
    }
    
    return 0;
}