#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
long long a[100009],b[100009],s[100009];
pair<long long,long long> p[100009];
long long ans;
main()
{long long n,S,sum=0;
cin>>n>>S;
for (long long i=0; i<n; i++)
{
    cin>>s[i]>>a[i]>>b[i];
    int x=(s[i]-s[i]%S);
    if(x-S>=0) x-=S;
    if(x-S>=0) x-=S;
    ans+=max(a[i],b[i])*x;
    s[i]-=x;
    
    sum+=s[i];
    ans+=b[i]*s[i];
    a[i]-=b[i];
    p[i]={a[i],s[i]};
}
p[n]={0,(S-sum%S)%S};
n++;
sort(p,p+n);
reverse(p,p+n);
for (long long i=0; i<n;)
{
    long long X=0,W=0;
    while(i<n && X<S)
    {
        long long q=min(p[i].second,S-X);
        X+=q;
        W+=p[i].first*q;
        p[i].second-=q;
        if(p[i].second==0) i++;
    }
    //cout<<W<<endl;
    if(W<0) break;
    ans+=W;
}
cout<<ans<<endl;
/*
6 10
7 -3
5 0
12 -3
6 5
3 -4
5 3
*/

}