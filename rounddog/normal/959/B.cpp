#include<bits/stdc++.h>
#define maxn 234000
#define M1 998244353
#define M2 100000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
map <string,int> f;
int n,l,m,k,a[maxn];
ll ans,p,q,b[maxn];
string s;

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1;i<=n;i++){
        cin >> s;
        f[s]=i;
    }
    for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&l);
        for (int j=0;j<l;j++) scanf("%d",&a[j]);
        p=b[a[0]]; for (int j=1;j<l;j++) p=min(p,b[a[j]]);
        for (int j=0;j<l;j++) b[a[j]]=p;
    }
    for (int i=0;i<m;i++)
    {
        cin >> s;
        ans+=b[f[s]];
    }
    cout << ans << endl;
}