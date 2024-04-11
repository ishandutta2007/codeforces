#include<bits/stdc++.h>

using namespace std;

string s,t;
int n,m;

int b[1001];

bool check(int pos)
{
    int i;

    if(pos+m>n)
        return 0;

    for(i=0;i<m;i++)
        if(s[i+pos]!=t[i])
            return 0;

    return 1;
}

int sum(int l,int r)
{
    if(l>r)
        return 0;

    if(l==0)
        return b[r];

    return b[r]-b[l-1];
}

int main ()
{
    int q,i,x,y;


    cin>>n>>m>>q;

    cin>>s>>t;

    for(i=0;i<n;i++)
        b[i]=check(i);

    for(i=1;i<n;i++)
        b[i]+=b[i-1];

    for(i=0;i<q;i++)
    {
        cin>>x>>y;

        x--;
        y--;
        y-=m-1;

        cout<<sum(x,y)<<"\n";
    }

    return 0;
}