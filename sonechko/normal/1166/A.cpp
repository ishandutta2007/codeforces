#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

int p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        p[s[0]-'a']++;
    }
    int ans=0;
    for (int j=0; j<=26; j++)
    {
        int t1=p[j]/2;
        int t2=p[j]-t1;
        ans+=t1*(t1-1)/2;
        ans+=t2*(t2-1)/2;
    }
    cout<<ans<<"\n";
}