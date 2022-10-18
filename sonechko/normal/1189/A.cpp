#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k0=0,k1=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='0') k0++; else k1++;
    if (k0!=k1)
    {
        cout<<1<<endl;
        cout<<s<<endl;
        return 0;
    }
    cout<<2<<endl;
    cout<<s[0]<<" ";
    for (int j=1; j<s.size(); j++)
        cout<<s[j];
    cout<<endl;
}