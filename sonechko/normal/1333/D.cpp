#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e6 + 11;

vector<int> vv[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ks=0;
    while (1)
    {
        ks++;
        for (int i=1; i<s.size(); i++)
            if (s[i-1]=='R'&&s[i]=='L') vv[ks].pb(i);
        if (vv[ks].size()==0) {ks--; break;}
        for (int i=0; i<vv[ks].size(); i++)
        {
            s[vv[ks][i]-1]='L';
            s[vv[ks][i]]='R';
        }
        if (ks>k) return cout<<"-1", 0;
    }
    if (ks>k) return cout<<"-1", 0;
    int kk=0;
    for (int i=1; i<=ks; i++)
        kk+=vv[i].size();
    if (kk<k) return cout<<"-1", 0;
    k-=ks;
    for (int i=1; i<=ks; i++)
    {
        while (vv[i].size()>1&&k>0)
        {
            k--;
            cout<<1<<" "<<vv[i].back()<<"\n";
            vv[i].pop_back();
        }
        cout<<vv[i].size()<<" ";
        for (int j=0; j<vv[i].size(); j++)
            cout<<vv[i][j]<<" ";
        cout<<"\n";
    }
}
/**

20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 1 1 1 1 1 1 1 2  3  3  4  5  5  6  7  8  9  10

**/