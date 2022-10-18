#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD
#define sqr(a) ((a)*(a))

const int N = 3e5 + 11;
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r,d;
    cin>>r>>d;
    int ans=0;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int x,y,R;
        cin>>x>>y>>R;
        ld dis=dist(0,0,x,y);
        if (dis-(r-d+R)>=-0.0000001&&r-dis-R>=-0.0000001)
            ans++;
    }
    cout<<ans<<endl;
}