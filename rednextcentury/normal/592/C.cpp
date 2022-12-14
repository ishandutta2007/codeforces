#include<bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if (a%b==0)return b;
    if(b%a==0)return a;
    return gcd(b%a,a);
}
int main()
{
    unsigned long long t,w,b;
    cin>>t>>w>>b;
    unsigned long long j=gcd(w,b);
    unsigned long long ans=min(t,min(w,b)-1);
    if (((w/j)*b)/(w/j) == b)
    {
        unsigned long long lcm=b*(w/j);
        if (lcm<=t)
        {
            ans+=((t/lcm)-1)*(min(w,b));
            unsigned long long mx=lcm*(t/lcm);
            if (mx+min(w,b)-1>t)
                ans+=t-mx+1;
            else
                ans+=min(w,b);
        }
    }
    ans=min(ans,t);
    unsigned long long gc=gcd(ans,t);
    cout<<ans/gc<<'/'<<t/gc<<endl;
}