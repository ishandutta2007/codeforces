#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k0=0,k1=0,k2=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='0') k0++; else
        if (s[j]=='1') k1++; else
        if (s[j]=='2') k2++;
    int ans=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='1'&&k1>n/3&&k0<n/3)
        {
            k1--;
            k0++;
            s[j]='0';
        } else
        if (s[j]=='2'&&k2>n/3&&k0<n/3)
        {
            k2--;
            k0++;
            s[j]='0';
        }
    for (int j=0; j<s.size(); j++)
        if (s[j]=='2'&&k2>n/3&&k1<n/3)
        {
            k2--;
            k1++;
            s[j]='1';
        }
    for (int j=s.size()-1; j>=0; j--)
        if (s[j]=='0'&&k0>n/3&&k2<n/3)
        {
            k0--;
            k2++;
            s[j]='2';
        } else
        if (s[j]=='1'&&k1>n/3&&k2<n/3)
        {
            k1--;
            k2++;
            s[j]='2';
        }
    for (int j=s.size()-1; j>=0; j--)
        if (s[j]=='0'&&k0>n/3&&k1<n/3)
        {
            k0--;
            k1++;
            s[j]='1';
        }
    cout<<s<<endl;
}