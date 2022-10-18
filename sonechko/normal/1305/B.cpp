#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int kk=0;
    while (1)
    {
        int last=s.size()-1;
        vector<int> vv;
        for (int i=1; i<s.size(); i++)
            if (s[i]=='(')
        {
            while (s[last]=='(') last--;

            if (last>i) {vv.pb(i); vv.pb(last); last--;} else break;
        }
        if ((int)vv.size()==0) break;
        sort(vv.begin(),vv.end());
        kk++;
        for (int i=0; i<vv.size(); i++)
            v[kk].pb(vv[i]);
        string t="";
        int pos=0;
        for (int i=1; i<s.size(); i++)
        if (pos<vv.size()&&i==vv[pos]) {pos++;} else t+=s[i];
        t="."+t;
        s=t;
    }
    cout<<kk<<"\n";
    for (int i=1; i<=kk; i++)
    {
        cout<<v[i].size()<<"\n";
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}