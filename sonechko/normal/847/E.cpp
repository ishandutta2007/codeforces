#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
string s;
int n;
bool good(int l)
{
    int k1=-1,pr=-1;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='*'&&k1==-1&&pr==-1) k1=i; else
        if (s[i]=='P'&&pr==-1)
        {
            pr=i;
            if (k1==-1) k1=pr;
            if (i-k1>l) return false;
        } else
        if (s[i]=='P'&&pr!=-1)
        {
            k1=i;
            pr=i;
        } else
        if (s[i]=='*'&&pr!=-1)
        {
            if (k1==-1) k1=pr;
            if (min(pr-k1+pr-k1+i-pr,i-pr+i-pr+pr-k1)>l)
            {
                pr=-1;
                k1=i;
            }
        }
    }
    if (pr==-1&&k1!=-1) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    s="."+s;
    int l=0,r=3*n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else cout<<r<<endl;
}