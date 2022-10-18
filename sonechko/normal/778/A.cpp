#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
string s,t;
int a[N],use[N];
bool good(int k)
{
    for (int i=0; i<s.size(); i++)
        use[i]=0;
    for (int i=0; i<k; i++)
        use[a[i]]=1;
    int l=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]==t[l]&&use[i]==0) l++;
        if (l==t.size()) return true;
    }
    return false;
}
int main()
{
    cin>>s>>t;
    for (int i=0; i<s.size(); i++)
        {
            cin>>a[i];
            a[i]--;
        }
    int l=0,r=s.size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    if (good(r)) cout<<r<<endl; else cout<<l<<endl;
}