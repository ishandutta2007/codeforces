#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int k1[N],k2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        s="."+s;
        t="."+t;
        for (int j=0; j<26; j++)
        {
            k1[j]=0;
            k2[j]=0;
        }
        for (int i=1; i<=n; i++)
            k1[s[i]-'a']++;
        for (int i=1; i<=n; i++)
            k2[t[i]-'a']++;
        int tt=0;
        for (int j=0; j<26; j++)
        if (k1[j]!=k2[j]) tt=1;
        if (tt==1) {cout<<"NO\n"; continue;}
        for (int j=0; j<26; j++)
            if (k1[j]>1) tt=1;
        if (tt==1) {cout<<"YES\n"; continue;}
        int kk=0;
        for (int i=1; i<=n; i++)
            if (s[i]!=t[i])
        {
            int ps=0;
            for (int j=i+1; j<=n; j++)
            if (s[j]==t[i]) ps=j;
            for (int j=ps-1; j>=i; j--)
            {
                swap(s[j],s[j+1]);
                kk++;
            }
        }
        if (kk%2==0) cout<<"YES\n"; else cout<<"NO\n";
    }
}