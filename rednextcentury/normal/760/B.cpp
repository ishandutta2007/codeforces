#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m,k;
int main()
{
    fast
    cin>>n>>m>>k;
    if (n==1)
    {
        cout<<m<<endl;
        return 0;
    }
    if (n==2)
    {
        cout<<m/2+m%2<<endl;
        return 0;
    }
    long long L=(k-1),R=(n-k);
    long long l=0,r=0;
    int num=1;
    m=m-n;
    while(1)
    {
        long long need = 1+l+r;
        if (L)l++,L--;
        if (R)r++,R--;
        if (need<=m)
            m-=need,num++;
        else break;
    }
    cout<<num<<endl;
}