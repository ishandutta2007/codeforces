#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long

const int N = 1e6 + 11;

vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l].pb(i);
    }
    for (int i=1; i<=n; i++)
    {
        if (v[i].size()==0) continue;
        int kol=0;
        for (int j=0; j<v[i].size(); j++)
            if (v[v[i][j]].size()==0) kol++;
        if (kol<3) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
}