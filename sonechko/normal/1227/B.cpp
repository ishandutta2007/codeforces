#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2e5 + 11;


void up()
{
    int n;
    cin>>n;
    vector<int> vv;
    vector<int> ans;
    int res=1;
    int c=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        for (int j=c+1; j<x; j++)
            vv.pb(j);
        if (x<c) res=-1; else
        if (x>c) {ans.pb(x);} else
        if (vv.size()==0) res=-1; else
            {
                ans.pb(vv.back());
                vv.pop_back();
            }
        c=x;
    }
    if (res==-1) {cout<<-1<<"\n"; return;}
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    cout<<"\n";
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