#include<iostream>
#define endl "\n"

using namespace std;

int a[100001];

int main ()
{
    string s;
    int n,m,i,l,r;

    ios::sync_with_stdio(false);

    cin>>s;
    n=s.size();
    if(s[0]==s[1])a[0]=1;
    for(i=1;i<n-1;i++)
    {
        if(s[i]==s[i+1])a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    a[n-1]=a[n-2];

    cin>>m;

    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        l--;
        r--;
        r-=1;
        if(l==0)cout<<a[r]<<endl;
        else cout<<a[r]-a[l-1]<<endl;
    }

    return 0;
}