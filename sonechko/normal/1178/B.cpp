#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    ll k1=0,k2=0,k3=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='v'&&j>0&&s[j-1]=='v')
    {
        k1++;
        k3+=k2;
    } else
        if (s[j]=='o')
        {
            k2+=k1;
        }
    cout<<k3;
}