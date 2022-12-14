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

pii a[125252], b[125252];

using ull = unsigned long long;

ull zobrist[125252];

ull compAX[252521], compAY[252521];
ull compBX[252521], compBY[252521];

ull ansA[125252], ansB[125252];

bool solve(){
    fill(zobrist, zobrist+n, 0ull);
    fill(compAX, compAX+n+n, 0ull);
    fill(compAY, compAY+n+n, 0ull);
    fill(compBX, compBX+n+n, 0ull);
    fill(compBY, compBY+n+n, 0ull);
    fill(ansA, ansA+n, 0ull);
    fill(ansB, ansB+n, 0ull);
    // zaatu
    {
        set<int> S;
        map<int,int> M;
        int it = 0;
        REP(i,n){
            S.insert(a[i].first);
            S.insert(a[i].second);
        }
        for(int x : S)M[x] = it++;
        REP(i,n){
            a[i].first = M[a[i].first];
            a[i].second = M[a[i].second];
        }
    }
    {
        set<int> S;
        map<int,int> M;
        int it = 0;
        REP(i,n){
            S.insert(b[i].first);
            S.insert(b[i].second);
        }
        for(int x : S)M[x] = it++;
        REP(i,n){
            b[i].first = M[b[i].first];
            b[i].second = M[b[i].second];
        }
    }
    // hash val
    mt19937 mt(random_device{}());
    uniform_int_distribution<ull> dist(0, ULLONG_MAX);
    REP(i,n)zobrist[i] = dist(mt);
    REP(i,n){
        compAX[a[i].first] ^= zobrist[i];
        compAY[a[i].second] ^= zobrist[i];
        compBX[b[i].first] ^= zobrist[i];
        compBY[b[i].second] ^= zobrist[i];
    }
    // MO
    const int B = 500;
    {
        vi order(n);
        REP(i,n)order[i] = i;
        sort(ALL(order), [&](int i, int j){
            if(a[i].first/B != a[j].first/B)return a[i].first < a[j].first;
            return a[i].second < a[j].second;
        });
        int l=0, r=0;
        ll hsh = 0;
        for(int id : order){
            while(l > a[id].first)hsh ^= compAY[--l];
            while(r < a[id].second+1)hsh ^= compAX[r++];
            while(l < a[id].first)hsh ^= compAY[l++];
            while(r > a[id].second+1)hsh ^= compAX[--r];
            ansA[id] = hsh;
            // printf("id=%d: [%d,%d) -> %llu\n", id, l, r, hsh);
        }
    }
    {
        vi order(n);
        REP(i,n)order[i] = i;
        sort(ALL(order), [&](int i, int j){
            if(b[i].first/B != b[j].first/B)return b[i].first < b[j].first;
            return b[i].second < b[j].second;
        });
        int l=0, r=0;
        ll hsh = 0;
        for(int id : order){
            while(l > b[id].first)hsh ^= compBY[--l];
            while(r < b[id].second+1)hsh ^= compBX[r++];
            while(l < b[id].first)hsh ^= compBY[l++];
            while(r > b[id].second+1)hsh ^= compBX[--r];
            ansB[id] = hsh;
            // printf("id=%d: [%d,%d) -> %llu\n", id, l, r, hsh);
        }
    }
    REP(i,n)if(ansA[i] != ansB[i]){
        // DEBUG(i);
        return false;
    }
    return true;
}

int main(){
    // while(true){
    //     n = 4;
    //     REP(i,n){
    //         int x = rand()%20, y = rand()%20;
    //         if(x>y)swap(x,y);
    //         a[i] = pii(x,y);
    //         x = rand()%20, y = rand()%20;
    //         if(x>y)swap(x,y);
    //         b[i] = pii(x,y);
    //     }

    //     bool ans = solve();
        
    //     bool naive = true;
    //     FOR(mask, 1, 1<<n){
    //         vi ids;
    //         REP(i,n)if(mask>>i&1)ids.push_back(i);
    //         bool ova = false, ovb = false;
    //         REP(i,ids.size())REP(j,i){
    //             int s = ids[i];
    //             int t = ids[j];
    //             ova = ova || max(a[s].first, a[t].first) <= min(a[s].second, a[t].second);
    //             ovb = ovb || max(b[s].first, b[t].first) <= min(b[s].second, b[t].second);
    //         }
    //         if(ova != ovb)naive = false;
    //     }
        
    //     if(ans != naive){
    //         printf("%d\n", n);
    //         REP(i,n)printf("%d %d %d %d\n",a[i].first,a[i].second,b[i].first,b[i].second);
    //         DEBUG(ans);
    //         DEBUG(naive);
    //         break;
    //     }
    // }
    // return 0;

    scanf("%d", &n);
    REP(i,n){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i] = pii(x,y);
        scanf("%d%d",&x,&y);
        b[i] = pii(x,y);
    }
    puts(solve() ? "YES" : "NO");
    return 0;
}