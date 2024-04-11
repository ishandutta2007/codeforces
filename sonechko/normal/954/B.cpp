#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=s.size();
    string t="";
    for (int j=0; j<n; j++)
    {
        t+=s[j];
        string d=t+t;
        int ps=0;
        for (int k=0; k<d.size(); k++)
            if (k>=s.size()||s[k]!=d[k]) ps=1;
        if (ps==0) res=min(res,(int)t.size()+1+(int)(s.size()-d.size()));
    }
    cout<<res<<endl;
}