#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int pre[1000000];
int suf[1000000];
int main()
{
    fast_io
    string a,b;
    cin>>a>>b;
    pre[0]=0;
    for (int i=1;i<=b.size();i++)
    {
        pre[i]=pre[i-1]+1;
        if (i==1)
            pre[i]=0;
        while(pre[i]<a.size() && a[pre[i]]!=b[i-1])
            pre[i]++;
    }
    reverse(b.begin(),b.end());
    reverse(a.begin(),a.end());
    suf[0]=0;
    for (int i=1;i<=b.size();i++)
    {
        suf[i]=suf[i-1]+1;
        if (i==1)
            suf[i]=0;
        while(suf[i]<a.size() && a[suf[i]]!=b[i-1])
            suf[i]++;
    }
    for (int i=1;i<=b.size();i++)
        pre[i]++,suf[i]++;
    int r=b.size();
    int ans=0,bl=0,br=0;
    for (int l=0;l<=b.size();l++)
    {
        while(r>0 && (suf[r]+pre[l]>a.size() || r+l>b.size()))
            r--;
        if (suf[r]+pre[l]<=a.size() && r+l<=b.size())
        {
            if (l+r>ans)
                ans=l+r,bl=l,br=r;
        }
    }
    string s1="",s2="";
    if (bl!=0){
        s1=b.substr(b.size()-bl,bl);
        reverse(s1.begin(),s1.end());
    }
    if (br!=0){
        s2=b.substr(0,br);
        reverse(s2.begin(),s2.end());
    }
    if (s1.length()+s2.length()==0)
        cout<<"-\n";
    else
    cout<<s1+s2<<endl;
}