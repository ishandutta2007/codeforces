#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const ll N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    for (int i=1; i<n; i++)
        if (s[i]>s[i+1])
    {
        for (int j=1; j<i; j++)
            cout<<s[j];
        for (int j=i+1; j<=n; j++)
            cout<<s[j];
        return 0;
    }
    for (int j=1; j<n; j++)
        cout<<s[j];
}