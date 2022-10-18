#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

vector<int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int d=0;
    set<int> st0,st1;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='0')
        {
            if (st1.size()==0)
            {
                d++;
                a[d].pb(i+1);
                st0.insert(d);
            } else
            {
                int p=*st1.begin();
                st1.erase(p);
                a[p].pb(i+1);
                st0.insert(p);
            }
        } else
        {
            if (st0.size()==0)
            {
                cout<<"-1"<<endl;
                return 0;
            } else
            {
                int p=*st0.begin();
                st0.erase(p);
                a[p].pb(i+1);
                st1.insert(p);
            }
        }
    if (st1.size()!=0) {cout<<"-1"<<endl; return 0;}
    cout<<d<<"\n";
    for (int i=1; i<=d; i++)
    {
        cout<<a[i].size()<<" ";
        for (int j=0; j<a[i].size(); j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
/**

01010101010010

**/