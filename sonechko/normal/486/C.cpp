#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 2e5 + 11;
const int MOD = 1e6 + 3;
#define mod %MOD
int n,m;
int g(char ch1, char ch2)
{
    int k1=0,k2=0;
    char ch=ch1;
    while (ch!=ch2)
    {
        k1++;
        if (ch=='z') ch='a'; else ch++;
    }
    ch=ch1;
    while (ch!=ch2)
    {
        k2++;
        if (ch=='a') ch='z'; else ch--;
    }
    return min(k1,k2);
}
int gg(int l)
{
    if (l<m) return min(m-l,l+n-m);
    return min(l-m,m+n-l);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    s='.'+s;
    int ans=0;
    int l1=0,r1=0,l2=0,r2=0;
    for (int i=1; i<=n/2; i++)
        if (s[i]!=s[n-i+1]) {l1=i; r2=n-i+1; break;}
    for (int i=n/2; i>=1; i--)
        if (s[i]!=s[n-i+1]) {r1=i; l2=n-i+1; break;}
    for (int i=1; i<=n/2; i++)
        ans+=g(s[i],s[n-i+1]);
    if (l1==0) {cout<<0<<endl; return 0;}
    ans+=r1-l1;
    int p=gg(l1);
    p=min(p,gg(r1));
    p=min(p,gg(l2));
    p=min(p,gg(r2));
    ans+=p;
    cout<<ans<<endl;
}