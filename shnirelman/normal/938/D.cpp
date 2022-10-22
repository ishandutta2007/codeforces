#include <iostream>
#include <set>
#include <vector>

using namespace std;

const long long inf = 1000000000000000000;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long> > > a(n, vector<pair<int, long long> >());
    for(int i = 0; i < m; i++){
        int v, u;
        long long w;
        cin >> v >> u >> w;
        v--;
        u--;
        w *= 2;
        a[v].push_back({u, w});
        a[u].push_back({v, w});
    }

    vector<long long> b(n);
    for(int i = 0; i < n; i++)cin >> b[i];

    set<pair<long long, int> > s;

    vector<long long> d(n);
    for(int i = 0; i < n; i++)d[i] = b[i];

    for(int i = 0; i < n; i++)
        s.insert({d[i], i});

    while(!s.empty()){
        int v = -1;
        long long w = inf;
        while(true){
            v = s.begin() -> second;
            w = s.begin() -> first;
            s.erase(s.begin());
            if(w <= d[v]){
                d[v] = w;
                break;
            }
            if(s.empty()){
                break;
            }
        }
//cout << v << ' ';
        for(int i = 0; i < a[v].size(); i++){
            //cout << a[v][i].first << ' ';
            if(d[a[v][i].first] > a[v][i].second + d[v])
                s.insert({a[v][i].second + d[v], a[v][i].first});
        }
        //cout << v << ' ' << d[v] << endl;


    }

    for(int i = 0; i < n; i++)cout << d[i] << ' ';
}