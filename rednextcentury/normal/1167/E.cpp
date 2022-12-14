#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int a[2000000];
vector<pair<int,int> > vec;
set<int> s;
int best[2000000];
int worst[2000000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int mx=1;
    for (int i=1;i<=x;i++)
        worst[i]=10000000;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        s.insert(a[i]);
        auto it = s.upper_bound(a[i]);
        best[a[i]]=max(best[a[i]],mx);
        if (it!=s.end())
            worst[a[i]]=min(worst[a[i]],*it);
        mx=max(mx,a[i]);
    }
    mx = 1;
    for (int i=1;i<=x;i++)
    {
        if (best[i]>i)
            vec.push_back({i,best[i]}),mx=i;
    }
    long long ret=0;
    int mn = x+1;
    int l=0;
    for (int i=1;i<=x;i++)
    {
        mx=max(mx,i);
        while(l<vec.size() && vec[l].first<i)
        {
            mn=min(mn,worst[vec[l].first]);
            mx=max(mx,vec[l].second);
            l++;
        }
        if (mn>=i)
            ret+=x-mx+1LL;

    }
    cout<<ret<<endl;
}