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

int n;
vi s[125252];

int main(){
    scanf("%d",&n);
    REP(i,n){
        int l;
        scanf("%d",&l);
        REP(j,l){
            int v;
            scanf("%d", &v);
            s[i].push_back(v);
        }
    }
    vi t1, t2;
    int asc = 0;
    REP(i,n){
        int len = s[i].size();
        bool ok = false;
        FOR(j,1,len)if(s[i][j-1] < s[i][j]){
            ok = true; break;
        }
        if(ok){
            asc++;
        }else{
            t1.push_back(*min_element(ALL(s[i])));
            t2.push_back(*max_element(ALL(s[i])));
        }
    }
    ll ans = 0;
    while(asc--){
        ans += 2*n-1;
        n--;
    }
    sort(ALL(t1)); sort(ALL(t2));
    reverse(ALL(t2));
    REP(i,n){
        int v = t1[i];
        while(t2.size()){
            if(t2.back() <= v){
                t2.pop_back();
            }else{
                break;
            }
        }
        ans += t2.size();
    }
    printf("%lld\n",ans);
    return 0;
}