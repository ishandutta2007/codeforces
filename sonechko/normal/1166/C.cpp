#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;

bool good(int l, int r)
{
    if (l>r) swap(l,r);
    if (l>=0&&r>=0)
    {
        if (r<=2*l) return 1;
        return 0;
    }
    if (l<=0&&r<=0)
    {
        if (2*r<=l) return 1;
        return 0;
    }
    if (-l<=r)
    {
        if (r<=-2*l) return 1;
        return 0;
    }
    if (-2*r<=l) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l>0) v1.pb(l); else v2.pb(l);
    }
    /**
    (n+1)/2..n*2
    **/
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int pos=0;
    ll ans=0;
    for (int j=0; j<v1.size(); j++)
    {
        while (pos+1<v1.size()&&v1[pos+1]<=v1[j]*2)
            pos++;
        ans+=1ll*(pos-j);
    }
    pos=0;
    for (int j=0; j<v2.size(); j++)
    {
        while (pos+1<v2.size()&&v2[pos+1]*2<=v2[j])
            pos++;
        ans+=1ll*(pos-j);
    }
    int l1=v2.size(),r1=v2.size()-1;
    for (int j=0; j<v1.size(); j++)
    {
        while (l1>0&&-v2[l1-1]<=v1[j]*2)
            l1--;
        while (r1>=0&&-v2[r1]<(v1[j]+1)/2)
            r1--;
        if (l1<=r1) {ans+=1ll*(r1-l1+1);}
    }
    cout<<ans<<"\n";
}
/**
|x-y|<=|x|<=|y|<=|x+y|


x<=y


x>=0
y>=0

y-x<=x

y<=2*x


x<=0
y<=0

-3 -2
y-x<=abs(y)
y<=abs(y)+x

y-abs(y)<=x


x<=0
y>=0

-3 2

abs(x+y)<=min(abs(x),y)

1. abs(x)<=y
    x+y<=abs(x)
    y<=abs(x)-x

2. abs(x)>=y
   -x-y<=y
   -2y<=x



**/