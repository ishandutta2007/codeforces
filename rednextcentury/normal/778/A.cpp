#include <bits/stdc++.h>
using namespace std;
int A[1000000];
bool check(string a,string b)
{
    int l=0;
    for (int i=0;i<a.size();i++)
    {
        if (l==b.size())
            return 1;
        if (a[i]==b[l])l++;
    }
    return l==b.size();
}
int del[1000000];
string a,b;
int tim=1;
string get(int m)
{
    for (int i=0;i<m;i++)
        del[A[i]-1]=tim;
    string ret="";
    for (int i=0;i<a.size();i++)
        if (del[i]!=tim)
            ret+=a[i];
    tim++;
    return ret;
}
int main()
{
    cin>>a>>b;
    int n=a.size();
    for (int i=0;i<n;i++)
        cin>>A[i];
    int l=0,r=n;
    int ret=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        string newA=get(mid);
        if (check(newA,b))
            l=mid+1,ret=mid;
        else r=mid-1;
    }
    cout<<ret<<endl;
}