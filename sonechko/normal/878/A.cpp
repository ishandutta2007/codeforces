#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
#define ld long double

const int N = 2e5 + 11;

int d[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int ii=1; ii<=n; ii++)
    {
        char ch;
        int l;
        cin>>ch>>l;
        if (ch=='|')
        {
            for (int i=0; i<=9; i++)
                if (l&(1<<i)) d[i]=1;
        }
        if (ch=='^')
        {
            for (int i=0; i<=9; i++)
                if (l&(1<<i))
                {
                    if (d[i]==-1) d[i]=1; else
                    if (d[i]==1) d[i]=-1; else
                    if (d[i]==0) d[i]=2; else
                    d[i]=0;
                }
        }
        if (ch=='&')
        {
            for (int i=0; i<=9; i++)
                if (l&(1<<i)) {}
                else d[i]=-1;
        }
    }
    int d1=0,d2=0,d3=0;
    for (int i=0; i<=9; i++)
    {
       if (d[i]==1) d1^=(1<<i); else
        if (d[i]==2) d2^=(1<<i);
        if (d[i]!=-1) d3^=(1<<i);
    }
    vector<char> v1;
    vector<int> v2;

     {v1.pb('&'); v2.pb(d3);}
     {v1.pb('|'); v2.pb(d1);}
    {v1.pb('^'); v2.pb(d2);}
    cout<<v1.size()<<endl;
    for (int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" "<<v2[i]<<endl;
}
/**
   ........
|3 ++......
^2 +-......
|1 +-......
**/