#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

long long v[100001],u[100001];

int main ()
{
    int n,i,m,l,r,type;
    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>v[i];
        u[i]=v[i];
    }

    sort(u,u+n);

    for(i=1;i<n;i++)
    {
        v[i]+=v[i-1];
        u[i]+=u[i-1];
    }

    cin>>m;

    for(i=0;i<m;i++)
    {
        cin>>type>>l>>r;
        l--;
        r--;

        if(type==1)
        {
            if(l==0)cout<<v[r]<<endl;
            else cout<<v[r]-v[l-1]<<endl;
        }
        else
        {
            if(l==0)cout<<u[r]<<endl;
            else cout<<u[r]-u[l-1]<<endl;
        }
    }

    return 0;
}