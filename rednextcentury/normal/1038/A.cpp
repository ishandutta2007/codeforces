#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int a[10000];
int main ()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        a[s[i]-'A']++;
    }
    int mn=10000000;
    for (int i=0;i<k;i++)
        mn=min(mn,a[i]);
    cout<<mn*k<<endl;
}