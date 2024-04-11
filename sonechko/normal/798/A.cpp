#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    s="."+s;
    int p=0;
    for (int i=1; i<=n; i++)
        if (s[i]!=s[n-i+1])
        {
            p++;
            if (p>1) {cout<<"NO"<<endl; return 0;}
            s[i]=s[n-i+1];
        }
    if (p==0&&n%2==0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
}