// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng(1234);

const int maxn=200007;
const int inf=LLONG_MAX/4;
int n;
int a[maxn],b[maxn];
set<int> s;
unordered_map<int,int> mp;
unordered_map<int,int> le[15],ri[15];
bool vis[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n){
        if (s.find(a[i])!=s.end()){
            cout<<"YES\n0 ";
            rep(j,n){
                if (i==j) continue;
                cout<<a[j]<<" ";
            }
            return 0;
        }
        s.insert(a[i]);
    }
    if (n>=4){
        bool ok=0;
        rep(i,n){
            if (a[i]&1) continue;
            ok=1;
        }
        if (ok){
            // cout<<"YES\n";
            int x=-1,y=-1;
            rep(i,n){
                if (a[i]&1) x=i;
                else y=i;
            }    
            int s=-1, t=-1;
            rep(i,n){
                if (i==x||i==y) continue;
                if (s==-1) s=i;
                else t=i;
            }   
            auto solve=[&](int s,int t,int d){
                int x=(a[s]+a[t]-a[d])/2;
                cout<<"YES\n"<<x<<" "<<a[s]-x<<" "<<a[t]-x<<" ";
                rep(i,n){
                    if (i==s||i==t||i==d) continue;
                    cout<<a[i]-x<<" ";
                }
            };
            if ((a[s]+a[t]+a[x])%2){
                solve(s,t,y);
            }
            else{
                solve(s,t,x);
            }
            return 0;
        }
        auto solve2=[&](int mask,int mask2){
            cout<<"YES\n";
            vi L,R;
            L.clear(), R.clear();
            rep(i,n){
                if (mask>>i&1) L.pb(a[i]), vis[i]=1;
                if (mask2>>i&1) R.pb(a[i]), vis[i]=1;
            }
            cout<<0<<" ";
            int ret=0;
            rep(i,sz(L)){
                ret=L[i]-ret; cout<<ret<<" ";
                ret=R[i]-ret; if (ret) cout<<ret<<" ";
            }
            rep(i,n){
                if (!vis[i]) cout<<a[i]<<" ";
            }
        };
        int m=min(n,30ll), k=m/2;
        vi p;
        p.clear();
        rep(i,m-k) p.pb(0);
        rep(i,k) p.pb(1);
        do{
            int sum=0,mask=0;
            rep(i,m) {
                if (p[i]) sum+=a[i], mask|=(1<<i);
            }
            if (mp[sum]){
                int mask2=mp[sum],com=mask&mask2;
                mask^=com, mask2^=com;
                solve2(mask,mask2);
                return 0;
            }
            mp[sum]=mask;
        }while (next_permutation(range(p)));
        cout<<"NO\n";
        return 0;
    }
    if (n==3){
        if ((a[0]+a[1]+a[2])%2){
            cout<<"NO";
            return 0;
        }
        cout<<"YES\n";
        int x=a[0]+a[1]-a[2];
        x/=2; cout<<x<<" "<<a[0]-x<<" "<<a[1]-x;
        return 0;
    }
    cout<<"NO\n";
    return 0;
}