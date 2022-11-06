#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    string s;
    cin >> s;
    int ans=s.size()/2;
    if(s.size()%2) {
        for(int j=1; j<s.size(); j++) {
            if(s[j]=='1') {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}