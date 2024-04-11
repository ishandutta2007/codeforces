#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

string a[N];
int use[N][30];

int get(int i, char ch)
{
    int k1=0,k2=0,kk=0,kol=0;
    for (int d=0; d<a[i].size(); d++)
        if (a[i][d]==ch) k1++; else break;
    for (int d=a[i].size()-1; d>=0; d--)
        if (a[i][d]==ch) k2++; else break;
    for (int d=0; d<a[i].size(); d++)
    {
        if (a[i][d]==ch) kk++; else kk=0;
        kol=max(kol,kk);
    }
    if (k1==(int)a[i].size())
    {
        if (i==1) {///cout<<i<<" 1 "<<k1<<endl;
        return k1;}
        int c=get(i-1,ch);
        ///cout<<i<<" 2 "<<c+(c+1)*k1<<endl;
        return c+(c+1)*k1;
    }
    int res=kol;
    if (use[i-1][ch-'a']>0) res=max(res,k1+1+k2);
    ///cout<<i<<" 3 "<<res<<endl;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        for (int j=0; j<26; j++)
            use[i][j]=use[i-1][j];
        for (int j=0; j<a[i].size(); j++)
            use[i][a[i][j]-'a']++;
    }
    int ans=0;
    for (int t=0; t<26; t++)
        ans=max(ans,get(n,t+'a'));
    cout<<ans<<endl;
}
/**
2
a
aa

a*aa=aaaaa

3
b
a
aa
**/