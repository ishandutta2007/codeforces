#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
bool ff(ll a,ll b)
{
    if(!a||!b)return 0;
    if(a>b)swap(a,b);
    bool v=ff(a,b%a);
    if(!v)return 1;
    ll c=b/a;
    if(a%2==1)return c%2==0;
    ll d=a+1;c--;
    ll e=c%d;
    if(e==d-1)return 1;
    if(e%2==0)return 0;
    return 1;
}
int main()
{
    int _;cin>>_;
    while(_--)
    {
        ll a,b;cin>>a>>b;
        puts(ff(a,b)?"First":"Second");
    }
    return 0;
}