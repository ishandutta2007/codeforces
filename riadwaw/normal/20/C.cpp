#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
 
using namespace std;
 
const int MX = 100100;
const long long INF = 1000000000000L;
 
long long n, m, dist[MX], prev[MX];
 
int main(void) {
    cin >> n >> m;
    vector<pair<long long, long long> > p[n + 1];
    for(int i = 1; i <= n; i++) { dist[i] = INF; prev[i] = -1; }
    for(int i = 0; i < m; i++) {
        long long a, b, c; cin >> a >> b >> c;
        p[a].push_back(make_pair(b, c));
        p[b].push_back(make_pair(a, c));
    }
    dist[1] = 0;
    set<pair<long long, long long> > pq;
    pq.insert(make_pair(dist[1], 1));
 
    while(!pq.empty()) {
        pair<long long, long long> tmp = (*pq.begin()); pq.erase(pq.begin());
        for(long long i = 0; i < p[tmp.second].size(); i++) {
            long long &ac_cost = dist[p[tmp.second][i].first];
            long long no_cost = tmp.first + p[tmp.second][i].second;
            if(no_cost < ac_cost) {
                ac_cost = no_cost;
                prev[p[tmp.second][i].first] = tmp.second;
                pq.insert(make_pair(dist[p[tmp.second][i].first], p[tmp.second][i].first));
            }
        }
    }
    if(dist[n] == INF) {
        cout << "-1" << endl;
    } else {
        vector<long long> ans;
        long long end = n;
        ans.push_back(end);
        while(prev[end] != -1) {
            ans.push_back(prev[end]);
            end = prev[end];
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            if(i == ans.size() - 1) {
                cout << ans[i] << endl;
            } else {
                cout << ans[i] << " ";
            }
        }
    }
    return 0;
}