#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    string t;
    cin>>t;
    for (int p=1; p<=min(s.size(),t.size()); p++)
    {
        if (s[s.size()-p]!=t[t.size()-p])
        {
            cout<<s.size()+t.size()-(p-1)*2;
            return 0;
        }
    }
    cout<<max(s.size(),t.size())-min(s.size(),t.size());
}
/**

**/