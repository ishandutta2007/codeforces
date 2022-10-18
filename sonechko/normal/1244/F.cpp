#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e5 + 11;

int n,k;
string s;
int k1[N],k2[N];

bool good(int x)
{
    if (x==0) x=n;
    if (x==n+1) x=1;
    if (s[x]==s[x-1]||s[x]==s[x+1]) return 1;
    return 0;
}

bool bad(int x)
{
    if (good(x)) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    cin>>s;
    s="."+s;
    s[0]=s[s.size()-1];
    s+=s[1];
    int c=0;
    for (int i=1; i<=n; i++)
        if (good(i)) c=1;
    if (c==0)
    {
        if (k%2==0)
            for (int i=1; i<=n; i++)
                cout<<s[i];
        else
            for (int i=1; i<=n; i++)
                if (s[i]=='B') cout<<'W'; else cout<<'B';
        cout<<endl;
        return 0;
    }
    int last=n;
    for (int i=n; i>=1; i--)
    if (good(i)) {last=i; break;}
    for (int i=1; i<=n; i++)
        if (bad(i))
    {
        k1[i]=i-last;
        if (last>i) k1[i]=(n-last)+i;
    } else last=i;
    last=1;
    for (int i=1; i<=n; i++)
    if (good(i)) {last=i; break;}
    for (int i=n; i>=1; i--)
        if (bad(i))
    {
        k2[i]=last-i;
        if (last<i) k2[i]=last+(n-i);
    } else last=i;


    for (int i=1; i<=n; i++)
        if (good(i)) cout<<s[i]; else
        if ((k1[i]+k2[i])%2==0)
    {
        char c=s[i];
        if (k1[i]%2==1)
        {
            if (c=='W') c='B'; else c='W';
        }
        if (k>=k1[i]||k>=k2[i]) cout<<c; else
        if (k%2==0) cout<<s[i]; else
        if (s[i]=='B') cout<<'W'; else cout<<'B';
    } else
        if (k1[i]<k2[i])
        {
            char c=s[i];
            if (k1[i]%2==1)
            {
                if (c=='W') c='B'; else c='W';
            }
            if (k>=k1[i]) cout<<c; else
            if (k%2==0) cout<<s[i]; else
            if (s[i]=='B') cout<<'W'; else cout<<'B';
        } else
        {
            char c=s[i];
            if (k2[i]%2==1)
            {
                if (c=='W') c='B'; else c='W';
            }
            if (k>=k2[i]) cout<<c; else
            if (k%2==0) cout<<s[i]; else
            if (s[i]=='B') cout<<'W'; else cout<<'B';
        }

}

/**
w b w b w b w b 0
w w b w b w b b 1
w w w b w b b b 2
w w w w b b b b 3

w b w b w b w 0
w w b w b w w 1
w w w b w w w 2
w w w w w w w 3


b w b w b
**/