#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s="."+s;
    int t=n+1;
    for (int i=1; i<=n; i++)
        if (i>k&&s[i]!=s[i-k]) {t=i; break;}
    if (t==n+1)
    {
        cout<<n<<endl;
        for (int i=1; i<=n; i++)
            cout<<s[i];
        cout<<endl;
        return 0;
    }
    if (s[t]<s[t-k])
    {
        for (int i=t; i<=n; i++)
            s[i]=s[i-k];
        cout<<n<<endl;
        for (int i=1; i<=n; i++)
            cout<<s[i];
        cout<<endl;
        return 0;
    }
    int pos=-1;
    for (int p=k; p>=1; p--)
        if (s[p]!='9') {pos=p; break;}
    if (pos!=-1)
    {
        s[pos]++;
        for (int p=pos+1; p<=k; p++)
            s[p]='0';
        for (int i=k+1; i<=n; i++)
            s[i]=s[i-k];
        cout<<n<<endl;
        for (int i=1; i<=n; i++)
            cout<<s[i];
        cout<<endl;
        return 0;
    }
    n++;
    s+="0";
    s[1]='1';
    for (int i=2; i<=k; i++)
        s[i]='0';
    for (int i=k+1; i<=n; i++)
        s[i]=s[i-k];
    cout<<n<<endl;
    for (int i=1; i<=n; i++)
        cout<<s[i];
        cout<<endl;
}