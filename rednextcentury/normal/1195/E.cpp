    #include <bits/stdc++.h>
    using namespace std;
     
    #define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #define ll long long
    #define ii pair<ll,ll>
    #define all(x) x.be,x.ee
    #define le (x*2)
    #define ri (x*2+1)
    #define mid ((l+r)/2)
    #define ld long double
    #define e '\n'
    #define sp ' '
    #define pb push_back
    #define pf push_front
    #define po pop_back()
    #define up upper_bound
    #define lo lower_bound
    #define in insert
    #define mk make_pair
    #define er erase
    #define R return
    #define se second
    #define co continue
    #define fi first
    #define fr front()
    #define ba back()
    #define si size()
    #define em empty()
    #define be begin()
    #define ee end()
    #define mod 998244353
    #define eb 0.000000001
    #define pi acos(-1)
     
    ll n,m,a,b,g0,x,y,z,arr[3030][3030],mn[3030][3030];
    ll ans;
    deque<int> dq;
     
    int main(){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,&g0,&x,&y,&z);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]=g0;
                while(!dq.em && arr[i][j]<arr[i][dq.fr]) dq.pop_front();
                dq.pf(j);
                if(j>=b-1){
                    while(dq.ba<j-b+1) dq.pop_back();
                    mn[i][j]=arr[i][dq.ba];
                }
                g0=(((g0%z)*(x%z))%z+y%z)%z;
            }
            dq.clear();
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                while(!dq.em && mn[i][j]<mn[dq.fr][j]) dq.pop_front();
                dq.pf(i);
                if(i>=a-1){
                    while(dq.ba<i-a+1) dq.pop_back();
                    ans+=min(mn[dq.ba][j],mn[i][j]);
                }
            }
            dq.clear();
        }
        printf("%lld",ans);
        R 0;
    }