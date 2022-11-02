
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

struct event{
    bool type; // true = new boi, false = sword
    ll time, index;
    operator> (const event &e) const {return time > e.time;}
};

int main(){
    ll n;
    cin >> n;
    vll as(n), bs(n), ts(n);
    for (ll i = 0; i < n; ++i) cin >> as[i] >> bs[i] >> ts[i];
    auto comp = [&](ll i, ll j){return ts[i] > ts[j];};
    priority_queue<ll, vll, decltype(comp)> q(comp);
    priority_queue<event, vector<event>, greater<event>> eq;
    for (ll i = 0; i < n; ++i) eq.push({true, as[i], i});
    ll current_start = -1, current_index = -1, current_event_index = -1, total = 0;
    while (!eq.empty()){
        event e = eq.top();
        eq.pop();
        if (e.type){
            q.push(e.index);
        }
        else if (current_event_index == e.index){
            total += (e.time - current_start) / ts[current_index];
            current_start = current_index = -1;
            q.pop();
        }
        while (!q.empty() && q.top() != current_index && e.time + ts[q.top()] > bs[q.top()]) q.pop();
        if (!q.empty() && q.top() != current_index){
            ll new_current_start = e.time;
            if (current_index != -1){
                ll new_swords = (e.time - current_start) / ts[current_index];
                total += new_swords;
                if (current_start + (new_swords + 1) * ts[current_index] <= bs[current_index])
                    new_current_start = min(new_current_start, current_start + (new_swords + 1) * ts[current_index] - ts[q.top()]);
            }
            current_start = new_current_start;
            current_index = q.top();
            ll boi_count = (bs[q.top()] - current_start) / ts[q.top()];
            eq.push({false, current_start + boi_count * ts[q.top()], ++current_event_index});
        }
    }
    cout << total << endl;
    return 0;
}