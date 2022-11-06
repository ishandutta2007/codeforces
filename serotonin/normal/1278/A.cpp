#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s,t;
        cin >> s >> t;
        bool yes=0;
        sort(s.begin(), s.end());
        for(int i=0; i<t.size(); i++) {
            string r;
            for(int j=0; j<s.size(); j++) {
                r+=t[i+j];
            }
            sort(r.begin(), r.end());
            if(s==r) yes=1;
        }
        if(yes) puts("YES");
        else puts("NO");
    }
}