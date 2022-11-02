#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

const int maxn=3e5+5;
ll tree[maxn*4];
ll arr[maxn];
ll n,m;
ll par[1010101];
ll arrans[1010101];

ll uf(ll a)
{
    if(par[a]==a) return a;
    par[a]=uf(par[a]);
    return par[a];
}


void upt(ll idx, ll val, ll s ,ll e,ll nod)
{
    //printf("%lld %lld %lld\n",s,e,nod);
	if(e<idx||s>idx) return ;
	if(s==e)
	{
		tree[nod]+=val;
		return;
	}
    tree[nod]+=val;
    upt(idx,val,s,(s+e)/2,nod*2);
    upt(idx,val,(s+e)/2+1,e,nod*2+1);
}

ll sol(ll l ,ll r, ll s,ll e,ll nod)
{
   // printf("%lld %lld %lld %lld\n",l,r,s,e);
	if(e<l||s>r) return 0;
	if(l<=s&&e<=r) return tree[nod];
	return sol(l,r,s,(s+e)/2,nod*2)
            +sol(l,r,(s+e)/2+1,e,nod*2+1);
}

int main()
{
	ll n,i,j,k,l,m,a,b,c;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		upt(i,i,1,n,1);
	}
	for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        par[i]=i;
    }

	for(i=n;i>=1;i--)
    {
        ll lo=1,hi=n+1;
        while(lo<hi)
        {
            ll mid=(lo+hi)/2;
            ll what=sol(1,mid-1,1,n,1);
           // printf("%lld %lld\n",mid,what);
            if(what<arr[i]) lo=mid+1;
            if(what==arr[i])
            {
                lo=mid;
                break;
            }
            if(what>arr[i]) hi=mid;
        }
        //printf("%lld %lld %lld\n",i,arr[i],lo);
        ll aans=uf(lo);
        upt(aans,-aans,1,n,1);
        par[aans]=uf(aans+1);
        arrans[i]=aans;
    }

    for(i=1;i<=n;i++)
        printf("%lld ",arrans[i]);

}