#include <bits/stdc++.h>
using namespace std;
#define ll long long
int x[1000000];
int y[1000000];
int z[1000000];
#define X first.first
#define Y first.second
#define Z second.first
#define id second.second
set<pair<pair<int,int>,pair<int,int> > > s;
bool taken[1000000];
bool In (int i,int j,int k)
{
    int lx = min(x[i],x[j]);
    int rx = max(x[i],x[j]);
    int ly = min(y[i],y[j]);
    int ry = max(y[i],y[j]);
    int lz = min(z[i],z[j]);
    int rz = max(z[i],z[j]);
    if (x[k]>=lx && x[k]<=rx)
        if (y[k]>=ly && y[k]<=ry)
            if (z[k]>=lz && z[k]<=rz)
                return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>x[i]>>y[i]>>z[i];
    for (int i=0;i<n;i++) {
        if (taken[i])continue;
        taken[i]=1;
        int cur = -1;
        for (int j=0;j<n;j++){
            if (taken[j])continue;
            if (cur==-1)cur=j;
            else {
                if (In(i,cur,j))
                    cur=j;
            }
        }
        cout<<i+1<<' '<<cur+1<<endl;
        taken[cur]=1;
    }
}