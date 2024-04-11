#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
using std::vector;
const ll q=3e5+5;
ll done[q];
vector <ll> tree[q];
ll n,f,b,t,crap=0,culprit[q],a;

void trav(ll x, ll w)
{
    done[x]=1;
    w++;
    for(ll i=0;i<tree[x].size();i++) {
        ll y=tree[x][i];
        if(done[y]==1) continue;
        if(crap==1) break;

        t=w;
        culprit[w]=y;
        if(y==b) crap=1;
        trav(y,w);
    }
}

void dfs(ll x)
{
    done[x]=1;
    for(ll i=0;i<tree[x].size();i++) {
        ll y=tree[x][i];
        if(done[y]==1) continue;

        a++;
        dfs(y);
    }
}

main() {
    ll i,j,k,x,y,z,w=1,a1,a2;
    cin >> n >> f >> b;
    done[n]=0;
    for(i=1;i<n;i++) {
        scanf("%I64d %I64d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
        done[i]=0;
    }

    culprit[w]=f;
    trav(f,w);

    for(i=1;i<=n;i++) done[i]=0;
    for(i=1;i<=t;i++) done[culprit[i]]=1;

    a=1;
    dfs(f);
    a1=a;

    a=1;
    dfs(b);
    a2=a;

    printf("%I64d\n", n*(n-1)-a1*a2);
}