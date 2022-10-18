#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

bool rec(string s, string t)
{
    for (int p=0; p<t.size()-s.size()+1; p++)
    {
        int ks=0;
        for (int j=0; j<s.size(); j++)
            if (s[j]!=t[p+j]) ks=1;
        if (ks==0) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,string> > vv;
    for (int j=1; j<=n; j++)
    {
        string s;
        cin>>s;
        vv.pb(mp(s.size(),s));
    }
    sort(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    {
        if (j!=0&&rec(vv[j-1].ss,vv[j].ss)==0) {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
    for (int j=0; j<vv.size(); j++)
        cout<<vv[j].ss<<"\n";
}