#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

map<ll,bool> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<ll> vv;
    for (int i=1; i<=(int)sqrt(n); i++)
        if (n%i==0)
    {
        ll d=n/i-1;

        ll sum=d*(d+1)/2;
        //cout<<i<<" -> "<<d<<" - "<<sum<<" ";
        sum*=i;
        sum+=n/i;
        //cout<<sum<<endl;
        if (mt[sum]==0)
        {
            mt[sum]=1;
            vv.pb(sum);
        }

        d=i-1;
        sum=d*(d+1)/2;
        //cout<<d<<" - "<<sum<<" ";
        sum*=n/i;
        sum+=i;
        //cout<<sum<<endl;
        if (mt[sum]==0)
        {
            mt[sum]=1;
            vv.pb(sum);
        }
    }
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j]<<" ";
    cout<<endl;
}
/**
6
2 - 0 2 4 - (0+1+2+3)*2 + n/i
**/