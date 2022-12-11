#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define repl(i,x,y) for (int i = (x); i <= (y); i++)
#define INF 1e18
#define LSOne(S) (S & (-S))
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> li;
typedef vector<vector<li>> vv;
vector<ii> vec;
int ways(int amt) {
    vector<pair<int, int>> diffv;
    int cur = 0;
   /* auto addint = [&](int l, int r) {
        diffarr[l]++;
        diffarr[r+1]--;
    };*/
    for (auto [l,r]: vec) {
        int sz = (r-l+1);
        if (sz >= amt) {
            cur++;continue;
        }
        int actl = l%amt;
        int actr= r%amt;
        if (actl <= actr) {
            diffv.emplace_back(actl, 1);
            diffv.emplace_back(actr+1, -1);
        } else {
            cur++;
            diffv.emplace_back(actr+1, -1);
            diffv.emplace_back(actl, +1);
        }
    }
    sort(begin(diffv), end(diffv));
    int bst = 0;
    int curr = 0;
    for (auto [x,ct]: diffv) {
        curr += ct;
        bst = max(bst, curr);
    }
    return bst + cur;
}
signed main() {
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    rep(i, 0, n) {
        int l,r;cin>>l>>r;
        vec.push_back(make_pair(l,r));
    }
    vector<int> ans(31);

    rep(i, 0, 31) {
        ans[i] = ways((1<<i));
    }
    /*rep(i, 0,10) {
        cout<<ans[i]<<",";
    }cout<<"\n";
    cout<<"....\n";*/
    int q;cin>>q;
    rep(i, 0, q) {
        int x;
        cin>>x;
        int po = __builtin_ctz(x);
        cout<<ans[po]<<"\n";
    }

}