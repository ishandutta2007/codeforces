#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

const ll MOD = 1000000007ll;

using P = complex<ll>;

int n;
P pts[2521];
P mul(const P &a, const P &b){
    return P(real(a)*real(b) - imag(a)*imag(b), real(a)*imag(b) + imag(a)*real(b));
}
ll dot(const P &a, const P &b){
    return real(a)*real(b) + imag(a)*imag(b);
}
ll cross(const P &a, const P &b){
    return real(a)*imag(b) - imag(a)*real(b);
}
int ccw(P a, P b, P c){
    b -= a; c -= a;
    if(cross(b,c) > 0)   return +1; // ccw
    if(cross(b,c) < 0)   return -1; // cw
    if(dot(b,c) < 0)     return +2; // c-a-b
    if(norm(b) < norm(c))return -2; // a-b-c
    return 0;
}

ll solve(int p){
    // count for a point p
    vi order;
    REP(i,n)if(i!=p)order.push_back(i);
    sort(order.begin()+1, order.end(), [&](int i, int j){
        if(pts[i] == pts[j])return false;
        if(ccw(pts[p], pts[order[0]], pts[i]) != ccw(pts[p], pts[order[0]], pts[j])){
            return ccw(pts[p], pts[order[0]], pts[i]) > ccw(pts[p], pts[order[0]], pts[j]);
        }
        return ccw(pts[p], pts[i], pts[j]) == +1;
    });
    // DEBUG(p);
    // DEBUG_VEC(order);
    vi val(n-1, 0);
    int it = 1;
    int cnt = 0;
    REP(i,n-1){
        while(it != n-1){
            if(ccw(pts[p], pts[order[i]], pts[order[it]]) == +1){
                // it = (it+1)%(n-1);
                it++;
                cnt++;
            }else{
                break;
            }
        }
        val[i] = cnt;
        // DEBUG(order[i]);
        // DEBUG(cnt);
        if(cnt==0){
            // it = (i+2) % (n-1);
            it = i+2;
            cnt = 0;
        }else{
            cnt--;
        }
    }
    vl sum(n);
    REP(i,n-1)sum[i+1] = sum[i] + (val[i] + i);

    ll ret = 0;
    FOR(i, 0, val[0]+1){
        ret -= 1ll * val[i] * (val[i] + i);
        ret += sum[min(n-1, i+val[i]+1)] - sum[i+1];
        // FOR(j, i+1, i+val[i]+1){
        //     ll add = (val[j] + j) - (val[i] + i);
        //     ret += add;
        // }
    }
    // FOR(j,1,val[0]+1){
    //     ret += 1ll * j * (val[j] + j);
    // }
    // REP(i,val[0]){
    //     ret -= 1ll * (val[0] - i) * (val[i] + i);
    // }
    // DEBUG(ret);
    ret = ret * (n-4) / 2;
    // DEBUG(p); DEBUG(ret);
    return ret;
}

int main(){
    scanf("%d",&n);
    REP(i,n){
        ll x,y;
        scanf("%lld%lld", &x, &y);
        pts[i] = P(x,y);
    }
    ll ans = 0;

    auto check = [&](vector<P> PP, P p){
        int cw = ccw(p, PP[0], PP[1]);
        if(cw != ccw(p, PP[1], PP[2]))return false;
        if(cw != ccw(p, PP[2], PP[0]))return false;
        return true;
    };

    REP(p,n){
        ll add = solve(p);
        ans += add;
        // ll naive = 0;
        // REP(mask, 1<<n){
        //     if(__builtin_popcount(mask) != 4)continue;
        //     if(mask>>p&1)continue;
        //     bool ok = false;
        //     vi ids;
        //     REP(i,n)if(mask>>i&1)ids.push_back(i);
        //     REP(mm,1<<4)if(__builtin_popcount(mm)==3){
        //         vector<P> PP;
        //         REP(i,4)if(mm>>i&1)PP.push_back(pts[ids[i]]);
        //         if(check(PP, pts[p])){
        //             DEBUG_VEC(ids);
        //             DEBUG(mm);
        //             ok = true;
        //         }
        //     }
        //     if(ok)naive++;
        // }
        // if(naive != add){
        //     DEBUG(p);
        //     DEBUG(add);
        //     DEBUG(naive);
        //     return 0;
        // }
    }
    printf("%lld\n",ans);
    return 0;
}