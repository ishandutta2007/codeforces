#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 11;



int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int nn;
        cin>>nn;
        string s;
        cin>>s;
        int pos=-1;
        for (int i=0; i<s.size(); i++)
            if (s[i]=='8') {pos=i; break;}
        if (pos==-1||s.size()-pos<11) cout<<"NO\n"; else cout<<"YES\n";
    }
}