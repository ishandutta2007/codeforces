#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=1; i<=5; i++)
    {
        string t;
        cin>>t;
        if (s[0]==t[0]||s[1]==t[1])
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}