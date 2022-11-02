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
typedef vector<vi> vvi;
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

#define MN 400005
int n;
int a[MN];
map<int, int> apps;
vpii pairs;
vvi gr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    F0R(i, n){
        cin >> a[i];
        apps[a[i]]++;
    }
    for(auto u : apps){
        pairs.pb({u.s, u.f});
        //cout << u.f << " " << u.s << "\n";
    }
    sort(pairs.begin(), pairs.end());

    int mp = 1, ma = pairs.size(); //assume p<=q
    int cur = 0;
    int cnt = pairs.size();
    FOR(i, 1, n){
        int o = cnt/i;
        if(i <= o && cnt-(cnt%i) > ma){
            mp = i; ma = cnt-(cnt%i);
        }
        while(cur != pairs.size() && pairs[cur].f == i){
            ++cur;
        }
        cnt = cnt+pairs.size()-cur;
        //cout << "cur is now " << cur << "\n";
    }
    //cout << mp << " " << ma << "\n";

    cout << ma << "\n" << mp << " " << ma/mp << "\n";
    int mq = ma/mp;

    gr.resize(mp);
    F0R(i, mp) gr[i].resize(mq);
    int cx = 0, cy = 0;
    cur = 0;
    RFOR(i, pairs.size()-1, 0){
        int amt = min(ma-cur, min(pairs[i].f, mp));
        F0R(j, amt){
            gr[cx][cy%mq] = pairs[i].s;
            ++cx; ++cy;
            if(cx == mp){
                cy = cy-cx+1;
                cx = 0;
            }
        }
        cur+=amt;
        if(cur == ma) break;
    }
    F0R(i, mp){
        F0R(j, mq){
            cout << gr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}