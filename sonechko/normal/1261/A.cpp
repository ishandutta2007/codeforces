#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;


void up()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string t="";
    while (k>1)
    {
        t+="()";
        k--;
        n-=2;
    }
    for (int j=1; j<=n/2; j++)
        t+="(";
    for (int j=1; j<=n/2; j++)
        t+=")";
    vector<pair<int,int> > vv;
    for (int p=0; p<t.size(); p++)
        if (t[p]!=s[p])
        {
            int pos=0;
            for (int j=p+1; j<t.size(); j++)
            if (s[j]==t[p]) {pos=j; break;}
            vv.pb(mp(p+1,pos+1));
            for (int j=p; j<=(p+pos)/2; j++)
                swap(s[j],s[pos-(j-p)]);
        }
    cout<<vv.size()<<"\n";
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ff<<" "<<vv[j].ss<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
    }
}
/**
x*y*z
**/