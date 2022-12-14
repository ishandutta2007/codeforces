#include<bits/stdc++.h>
using namespace std;
long long Try(long long a,long long b,long long c)
{
    if (a>b)swap(a,b);
    if (a+c<b)return a+c;
    else c-=b-a,a=b;
    return a+c/2;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<max(Try(a,b,c),max(Try(b,c,a),Try(a,c,b)))<<endl;
    }
}