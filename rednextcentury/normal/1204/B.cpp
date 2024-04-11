#include<bits/stdc++.h>
using namespace std;
long long getMin(int n,int l)
{
    long long cur=1;
    long long ret=0;
    while(l--)
    {
        ret+=cur,cur=cur*2;
        n--;
    }
    ret+=n;
    return ret;
}
long long getMax(int n,int l)
{
    long long cur=1;
    long long ret=0;
    while(l--)
    {
        ret+=cur,cur=cur*2;
        n--;
    }
    cur=cur/2;
    ret+=n*cur;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    cout<<getMin(n,l)<<' '<<getMax(n,r)<<endl;
}