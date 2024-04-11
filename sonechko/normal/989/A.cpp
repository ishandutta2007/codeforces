#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=2; i<s.size(); i++)
        if (s[i]!='.'&&s[i-1]!='.'&&s[i-2]!='.'&&
            s[i]!=s[i-1]&&s[i]!=s[i-2]&&s[i-1]!=s[i-2])
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}