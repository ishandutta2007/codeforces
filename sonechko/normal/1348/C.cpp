#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int kk[N];

void up()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0; i<=26; i++)
        kk[i]=0;
    for (int i=0; i<n; i++)
        kk[s[i]-'a']++;
    string ans="";
    int ks=0;
    for (int i=0; i<26; i++)
        if (kk[i]>0) ks++;
    if (ks==1)
    {
        int kol=(n+k-1)/k;
        for (int j=1; j<=kol; j++)
            ans+=s[0];
        cout<<ans<<"\n";
        return;
    }
    if (ks==2)
    {
        int t1=-1,t2=-1;
        for (int i=0; i<26; i++)
            if (kk[i]>0&&t1==-1) t1=i; else
            if (kk[i]>0) t2=i;
        if (kk[t1]==k)
        {
            ans+=char(t1+'a');
            int kol=(kk[t2]+k-1)/k;
            for (int j=1; j<=kol; j++)
                ans+=char(t2+'a');
            cout<<ans<<"\n";
            return;
        }
    }
    sort(s.begin(),s.end());
    if (s[k-1]==s[0])
    {
        for (int j=k-1; j<n; j++)
            cout<<s[j];
        cout<<"\n";
        return;
    }
    cout<<s[k-1]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**
2 a
4 b
6 c

a a a
b b b
b
**/