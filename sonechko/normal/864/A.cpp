#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 100 + 11;
int dp[N],pred[N];
int kol[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kol[a[i]]++;
    }
    for (int i=1; i<=100; i++)
    for (int j=1; j<=100; j++)
    if (i!=j&&kol[i]+kol[j]==n&&kol[i]==kol[j]) {cout<<"YES"<<endl;
    cout<<i<<" "<<j<<endl; return 0;}
    cout<<"NO"<<endl;
    return 0;
    vector<int> v,w;
    for (int i=1; i<=100; i++)
        if (kol[i]>=1) {v.pb(kol[i]); w.pb(i);}
    dp[0]=1;
    for (int i=0; i<v.size(); i++)
    for (int j=100; j>=0; j--)
    if (j-v[i]>=0&&dp[j-v[i]]==1) {dp[j]=1; pred[j]=i;}
    if (dp[n/2]==0) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    n/=2;
    while (n>0)
    {
        cout<<w[pred[n]]<<" ";
        n=n-v[pred[n]];
    }
}