#include<bits/stdc++.h>
using namespace std;
const int N = 250 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
string a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif
    int n,m;
    cin>>n>>m;
    int anss=INT_MAX;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++)
            if (i!=j&&j!=k&&i!=k)
    {
        string s="."+a[i];
        int ans=0,res=INT_MAX;
        for (int ij=1; ij<=m; ij++)
            if (s[ij]>='a'&&s[ij]<='z') res=min(res,min(ij-1,m-ij+1));
        if (res==INT_MAX) break;
        s="."+a[j];
        ans+=res;
        res=INT_MAX;
        for (int ij=1; ij<=m; ij++)
            if (s[ij]>='0'&&s[ij]<='9') res=min(res,min(ij-1,m-ij+1));
        if (res==INT_MAX) break;
        s="."+a[k];
        ans+=res;
        res=INT_MAX;
        for (int ij=1; ij<=m; ij++)
            if (s[ij]=='#'||s[ij]=='*'||s[ij]=='&') res=min(res,min(ij-1,m-ij+1));
        if (res==INT_MAX) break;
        ans+=res;
        anss=min(anss,ans);
    }
    cout<<anss<<endl;
}