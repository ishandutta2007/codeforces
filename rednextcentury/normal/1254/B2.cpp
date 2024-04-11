#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000500];
ll b[1000500];
vector<pair<ll,ll> > cur;
ll n1=0,n2=0,s1=0,s2=0;
void Init() {
    cur.clear();
    n1 = 0, n2 = 0, s1 = 0, s2 = 0;
}
void Add(pair<ll,ll> x){
    cur.push_back(x);
    n2+=x.first;
    s2+=x.first*x.second;
}
ll getCost() {
    if (cur.size()<=1)return 0;
    int opt=0;
    n1+=cur[0].first;
    s1+=cur[0].first*cur[0].second;
    n2-=n1;
    s2-=s1;
    ll best = n1*cur[opt].second - s1 + s2 - n2*cur[opt].second;
    while(opt+1<cur.size()){
        opt++;
        n1+=cur[opt].first;
        s1+=cur[opt].first*cur[opt].second;
        n2-=cur[opt].first;
        s2-=cur[opt].first*cur[opt].second;
        ll now = n1*cur[opt].second - s1 + s2 - n2*cur[opt].second;
        best = min(best,now);
    }
    return best;
}
int n;
ll Try(ll k){
    for (int i=1;i<=n;i++)a[i]=b[i]%k;
    ll C = 0;
    Init();
    ll ret=0;
    for (int i=1;i<=n;i++) {
        if (a[i]==0)continue;
        if (C+a[i]>=k){
            Add({k-C,i});
            a[i]-=k-C;
            C=0;
            i--;
            ret+=getCost();
            Init();
        } else {
            C+=a[i];
            Add({a[i],i});
        }
    }
    ret+=getCost();
    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    ll sum=0;
    for (int i=1;i<=n;i++) {
        scanf("%lld",&b[i]);
        sum+=b[i];
    }
    vector<ll> pos;
    for (ll x=2;x*x<=sum;x++) {
        if (sum % x == 0) {
            pos.push_back(x);
            while(sum%x==0)sum/=x;
        }
    }
    if (sum!=1)pos.push_back(sum);
    ll ret=(2e18) + 1;
    for (auto x:pos){
        ret=min(ret,Try(x));
    }
    if (ret>=2e18)ret=-1;
    printf("%lld\n",ret);
}