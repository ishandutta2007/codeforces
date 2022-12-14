#include <bits/stdc++.h>
using namespace std;
int mx[1000000][21];
vector<int> vec[1000000];
int N = 5e5;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        vec[l].push_back(r);
    }
    int best=0;
    for (int i=0;i<=N;i++) {
        best=max(best,i);
        for (auto x:vec[i])best=max(best,x);
        mx[i][0] = best;
    }
    for (int i=1;i<=20;i++) {
        for (int j=0;j<=N;j++) {
            mx[j][i]=mx[mx[j][i-1]][i-1];
        }
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int ret=0;
        for (int i=20;i>=0;i--) {
            if (mx[x][i]<y)x=mx[x][i],ret+=(1<<i);
        }
        ret++,x=mx[x][0];
        if (x>=y)cout<<ret<<endl;
        else cout<<-1<<endl;
    }
}