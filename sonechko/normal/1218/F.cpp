#include <bits/stdc++.h>

using namespace std;

#define DIM 400009
#define INF ((long long)1e18+9ll)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double
#define amen exit(0)
#define endl '\n'
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

long long i,j,k,l,n,m,cnt1,cnt2,sum1,sum2,res,a,start;

long long c[DIM],x[DIM];

priority_queue<long long,vector<long long>,greater<long long> >q;

int main()
{
    fast;

    cin>>n>>start;
    for(i=1;i<=n;i++)cin>>x[i];
    cin>>a;
    for(i=1;i<=n;i++)cin>>c[i];

    for(i=1;i<=n;i++){
        q.push(c[i]);
        while(!q.empty() && start<x[i]){
            start+=a;
            res+=q.top();
            q.pop();
        }
        if(start<x[i])return cout<<-1<<endl,0;
    }

    cout<<res<<endl;

    amen;
}