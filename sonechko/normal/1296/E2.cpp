#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int ans[N],use[N];
int kk[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    int res=0;
    for (int i=n; i>=1; i--)
    {
        ans[i]=0;
        for (int j=s[i]-'a'-1; j>=0; j--)
            ans[i]=max(ans[i],kk[j]);
        ans[i]++;
        kk[s[i]-'a']=max(kk[s[i]-'a'],ans[i]);
        res=max(res,ans[i]);
    }
    cout<<res<<"\n";
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}
/**
8
edcbjiha
**/