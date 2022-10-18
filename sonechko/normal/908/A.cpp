#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int ans=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||
            s[j]=='1'||s[j]=='3'||s[j]=='5'||s[j]=='7'||s[j]=='9')
            ans++;
    cout<<ans<<endl;
}