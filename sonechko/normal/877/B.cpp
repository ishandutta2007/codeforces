#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 11;
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s='.'+s;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i]=='a') a[i]=a[i-1]+1; else a[i]=a[i-1];
        if (s[i]=='b') b[i]=b[i-1]+1; else b[i]=b[i-1];
    }
    int ans=s.size();
    for (int i=0; i<s.size(); i++)
    for (int j=i; j<s.size(); j++)
    ans=min(ans,b[i]+a[j]-a[i]+b[s.size()-1]-b[j]);
    cout<<s.size()-1-ans<<endl;
}