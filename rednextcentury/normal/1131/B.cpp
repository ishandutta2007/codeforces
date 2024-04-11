#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long a=0,b=0;
    long long ret=1;
    int n;
    cin>>n;
    long long Lx=0,Ly=0;
    while(n--)
    {
        long long x,y;
        cin>>x>>y;
        if (Lx==x && Ly==y)continue;
        Lx=x,Ly=y;
        if (a<b && x>=b)a=b,ret++;
        if (b<a && y>=a)b=a,ret++;
        if (a==b) ret+=min(x,y)-a;
        a=x,b=y;
    }
    cout<<ret<<endl;
}