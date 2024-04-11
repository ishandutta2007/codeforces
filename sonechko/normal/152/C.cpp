#include<bits/stdc++.h>
using namespace std;
int use[1000][40],kol[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<m; j++)
        if (use[j][s[j]-'A']==0) {kol[j]++; use[j][s[j]-'A']=1;}
    }
    long long res=1;
    for (int j=0; j<m; j++)
    {
        res*=1LL*kol[j];
        res%=1000000007;
    }
    cout<<res<<endl;
}