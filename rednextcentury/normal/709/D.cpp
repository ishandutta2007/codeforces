#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
    long long A,B,C,D;
string Sol(long long l,long long r)
{
    if (b+c!=l*r)
    {
        return "-1";
        return 0;
    }
    string ret="";
    while(l>0 && b>=l)
    {
        b-=l;
        ret+="1";
        r--;
    }
    if (b>0)
    {
        while(l>b)
        {
            ret+="0";
            l--;
        }
        ret+="1";
        r--;
    }
    while(l)
    {
        l--;
        ret+="0";
    }
    while(r)
    {
        r--;
        ret+="1";
    }
    a=A,b=B,c=C,d=D;
    reverse(ret.begin(),ret.end());
    return ret;
}
int main()
{
    cin>>A>>B>>C>>D;
    if (A+B+C+D==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    long long l = 1;
    while(l*(l-1)/2 < A)
        l++;
    if (l*(l-1)/2 != A)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    long long r=1;
    while(r*(r-1)/2 < D)
        r++;
    if (r*(r-1)/2 != D)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    string ret="Impossible";
    if (l==1 && r==1)
    {
        a=A,b=B,c=C,d=D;
        if (Sol(l,r)!="-1")
            ret=Sol(l,r);

    a=A,b=B,c=C,d=D;
        if (Sol(l,r-1)!="-1")
            ret=Sol(l,r-1);

    a=A,b=B,c=C,d=D;
        if (Sol(l-1,r)!="-1")
            ret=Sol(l-1,r);

    a=A,b=B,c=C,d=D;
        if (Sol(l-1,r-1)!="-1")
            ret=Sol(l-1,r-1);
    }
    else if (l==1)
    {
    a=A,b=B,c=C,d=D;
        if (Sol(l,r)!="-1")
            ret=Sol(l,r);
    a=A,b=B,c=C,d=D;
        if (Sol(l-1,r)!="-1")
            ret=Sol(l-1,r);
    }
    else if (r==1)
    {
    a=A,b=B,c=C,d=D;
        if (Sol(l,r)!="-1")
            ret=Sol(l,r);
    a=A,b=B,c=C,d=D;
        if (Sol(l,r-1)!="-1")
            ret=Sol(l,r-1);
    }
    else {
    a=A,b=B,c=C,d=D;
        if (Sol(l,r)!="-1")
        {
            ret=Sol(l,r);
        }
    }
    cout<<ret<<endl;
}