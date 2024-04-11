#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long



const ll N = 2e5 + 11;

ll step[N];
map<ll,int> mt;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    int m;
    cin>>n>>m;
    ll p=n+1;
    ll g=p/2;
    ll kol=0;
    while (g!=0)
    {
        kol++;
        step[kol]=g;
        g/=2;
    }
    for (int i=1; i<=m; i++)
    {
        ll st;
        cin>>st;
        ll k=1,pp=p/2,type=1,gp=p/2;
        while (gp!=st)
        {
            k++;
            mt[gp]=type;
            if (st<gp) {gp-=step[k];type=1;} else
            {
                gp+=step[k];
                type=2;
            }
        }
        string s;
        cin>>s;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='U')
        {
            mt[st]=type;
            if (k!=1)
            {
                if (type==1) {st+=step[k]; k--; type=mt[st];} else
                {st-=step[k]; k--; type=mt[st];}
            }
        } else
        if (s[i]=='L')
        {
            mt[st]=type;
            if (st%2==0) {st-=step[k+1]; k++; type=1;}
        } else
        {
            mt[st]=type;
            if (st%2==0) {st+=step[k+1]; k++; type=2;}
        }
        }
        cout<<st<<endl;
    }
}