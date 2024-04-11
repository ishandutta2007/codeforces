#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
using namespace std;

const int MAXN = 100005;

typedef long long ll;

int N, L;
ll x[MAXN], d[MAXN], t[MAXN], p[MAXN]; 

vector<ll> allv;
vector<pair<ll, ll> > succ[2*MAXN];
ll dist[2*MAXN], pred[2*MAXN], how[2*MAXN];
ll rcst[MAXN];

int comp(ll coord){
    return lower_bound(allv.begin(), allv.end(), coord) - allv.begin();
}

vector<int> used;

void print_ramps(ll loc){
    if(loc == comp(0)) return;
    print_ramps(pred[loc]);
    if(how[loc]) used.push_back(how[loc]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> L;

    allv.push_back(0);
    allv.push_back(L);

    for(int i=0; i<N; i++){
        cin >> x[i] >> d[i] >> t[i] >> p[i];
        if(x[i] >= p[i]) {
            allv.push_back(x[i] - p[i]);
            allv.push_back(x[i] + d[i]);
        }
    }

    sort(allv.begin(), allv.end());
    allv.resize(unique(allv.begin(), allv.end()) - allv.begin());

    for(int i=1; i<allv.size(); i++){
        succ[i-1].emplace_back(i, allv[i] - allv[i-1]);
        succ[i].emplace_back(i-1, allv[i] - allv[i-1]);
    }

    for(int i=0; i<N; i++){
        rcst[i] = p[i] + t[i];
        if(x[i] >= p[i]){
            succ[comp(x[i] - p[i])].emplace_back(
                comp(x[i] + d[i]), -i);
        }
    }

    memset(dist, 0x3f, sizeof(dist));

    priority_queue<pair<ll, ll> > dij;
    dij.push(make_pair(0, 0));
    dist[0] = 0;

    while(!dij.empty()){
        auto p = dij.top();
        dij.pop();
        if(-p.first > dist[p.second]) continue; 

        for(auto q : succ[p.second]){
            int j = q.first;
            if(q.second <= 0){
                ll c = p.first - rcst[-q.second];
                if(-c < dist[j]){
                    dist[j] = -c;
                    pred[j] = p.second;
                    how[j] = -q.second+1;
                    dij.push(make_pair(c, j));
                }
            }
            else{
                ll c = p.first - q.second;
                if(-c < dist[j]){
                    dist[j] = -c;
                    pred[j] = p.second;
                    how[j] = 0;
                    dij.push(make_pair(c, j));
                }
            }
        }
    }

    cout << dist[allv.size()-1] << endl;
    print_ramps(allv.size()-1);
    cout << used.size() << endl;
    for(int r : used) cout << r << " ";
    cout << endl;
}