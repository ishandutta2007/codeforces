#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans,t;
    int res=2*n;
    for (int i1=0; i1<3; i1++)
    for (int i2=0; i2<3; i2++)
    for (int i3=0; i3<3; i3++)
    {
        int ress=0;
        t=s;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='R'&&i%3==i1) {} else
            if (s[i]=='B'&&i%3==i2) {} else
            if (s[i]=='G'&&i%3==i3) {} else
            {
                s[i]='.';
                if (i%3==i1) s[i]='R';
                if (i%3==i2) s[i]='B';
                if (i%3==i3) s[i]='G';
                if (s[i]=='.') ress=n*5;
                ress++;
            }
        }
        if (ress<res)
        {
            res=ress;
            ans=s;
        }
        s=t;
    }
    cout<<res<<endl;
    cout<<ans<<endl;

}