#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back

const int N = 2e5 + 11;

int nx[N][27];

void up()
{
    string s;
    string t;
    cin>>s>>t;
    int n=s.size();
    s="."+s;
    for (int i=0; i<=26; i++)
        nx[n+1][i]=-1;
    for (int i=n; i>=1; i--)
    {
        for (int j=0; j<=26; j++)
            nx[i][j]=nx[i+1][j];
        nx[i][s[i]-'a']=i;
    }
    int last=0,ans=1;
    for (int i=0; i<t.size(); i++)
    {
        last++;
        if (nx[1][t[i]-'a']==-1) {cout<<"-1\n"; return;}
        if (nx[last][t[i]-'a']==-1) {last=1; ans++;}
        last=nx[last][t[i]-'a'];
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
     up();
}