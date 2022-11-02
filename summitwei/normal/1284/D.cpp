#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 100005
int n;
pair<pii, int> a[MN], b[MN];
priority_queue<pii, vpii, greater<pii> > ree;
 
multiset<int> mns;
multiset<int> mxs;
 
bool aah(pair<pii, int> a, pair<pii, int> b){
    return a.s < b.s;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    F0R(i, n){
        cin >> a[i].f.f >> a[i].f.s >> b[i].f.f >> b[i].f.s;
        a[i].s = b[i].s = i;
    }
 
    bool ok = true;
    sort(a, a+n);
    F0R(i, n){
        //cout << "on " << i << "\n";
        int ct = a[i].f.f;
        while(!ree.empty() && ree.top().f < ct){
            int x = ree.top().s;
            ree.pop();
            mns.erase(mns.find(b[x].f.f));
            mxs.erase(mxs.find(b[x].f.s));
        }
        if(mxs.lower_bound(b[a[i].s].f.f) != mxs.begin()){
            ok = false;
        }
        if(mns.upper_bound(b[a[i].s].f.s) != mns.end()){
            ok = false;
        }
 
        mns.insert(b[a[i].s].f.f);
        mxs.insert(b[a[i].s].f.s);
        ree.push({a[i].f.s, a[i].s});
    }
 
    while(!ree.empty()) ree.pop();
    mns.clear();
    mxs.clear();
 
    sort(a, a+n, aah);
    sort(b, b+n);
    F0R(i, n){
        //cout << "on " << i << "\n";
        int ct = b[i].f.f;
        while(!ree.empty() && ree.top().f < ct){
            int x = ree.top().s;
            //cout << "erasing " << x << "\n";
            ree.pop();
            mns.erase(mns.find(a[x].f.f));
            mxs.erase(mxs.find(a[x].f.s));
        }
        //cout << "hmm\n";
        if(mxs.lower_bound(a[b[i].s].f.f) != mxs.begin()){
            ok = false;
        }
        if(mns.upper_bound(a[b[i].s].f.s) != mns.end()){
            ok = false;
        }
 
        mns.insert(a[b[i].s].f.f);
        mxs.insert(a[b[i].s].f.s);
        ree.push({b[i].f.s, b[i].s});
    }
 
    if(ok) cout << "YES\n";
    else cout << "NO\n";
 
    return 0;
}