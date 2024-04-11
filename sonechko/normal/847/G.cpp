#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int kol[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<s.size(); j++)
            if (s[j]=='1') kol[j]++;
    }
    int ans=0;
    for (int i=0; i<=7; i++)
        ans=max(ans,kol[i]);
    cout<<ans<<endl;
}