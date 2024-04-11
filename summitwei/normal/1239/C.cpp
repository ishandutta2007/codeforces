#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
ll p;
pll t[MN];
queue<int> bleh;
priority_queue<int, vector<int>, greater<int> > bruh;
ll ans[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    F0R(i, n){
        cin >> t[i].f;
        t[i].s = i+1;
    }
    sort(t, t+n);
    F0R(i, n){
        //cout << i << " " << t[i].f << " " << t[i].s << "\n";
        ll curt = t[i].f;
        int val = t[i].s;
        ll lst = 0;
        while(!bleh.empty() && ans[bleh.front()] <= curt){
            lst = ans[bleh.front()];
            bleh.pop();
        }
        if(bleh.empty()){
            for(ll i=lst; i<=curt; i+=p){
                if(bruh.empty()) break;
                if(!bleh.empty()) bleh.pop();
                if(i == curt && val < bruh.top()) break;
                int top = bruh.top();
                bruh.pop();
                ans[top] = i+p;
                lst = i+p;
                bleh.push(top);
            }
        }
        if(bleh.empty() || bleh.back() > t[i].s){
            if(!bleh.empty()) lst = max(lst, ans[bleh.back()]);
            ans[t[i].s] = max(lst, t[i].f)+p;
            bleh.push(t[i].s);
        } else{
            bruh.push(t[i].s);
        }
    }
    ll lst = 0;
    while(!bleh.empty()){
        lst = ans[bleh.front()];
        bleh.pop();
    }
    for(ll i = lst; !bruh.empty(); i+=p){
        if(!bleh.empty()) bleh.pop();
        int top = bruh.top();
        bruh.pop();
        ans[top] = i+p;
        bleh.push(top);
    }

    FOR(i, 1, n){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}