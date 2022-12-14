#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
inline int query(int x,int y)
{
    cout<<"? "<<x<<' '<<y<<endl;
    int z;
    cin>>z;
    return z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    pi cm(inf,0);
    for(int i=1;i<=m;i++)
        cm=min(cm,pi(query(1,i),i));
    for(int i=1;i<=n;i++)
        cm.fi=min(cm.fi,query(i,cm.se));
    cout<<"! "<<cm.fi<<endl;
    return 0;
}