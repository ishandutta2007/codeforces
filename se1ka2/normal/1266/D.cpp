#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    int n, m;
    cin >> n >> m;
    ll s[100005] {0};
    P p[100005];
    for(int i = 0; i < m; i++){
        int u, v;
        ll d;
        cin >> u >> v >> d;
        u--; v--;
        s[u] -= d;
        s[v] += d;
    }
    for(int i = 0; i < n; i++) p[i] = P(s[i], i);
    sort(p, p + n);
    vector<int> u, v;
    vector<ll> d;
    int i = 0;
    int j = n - 1;
    while(i < j){
        if(p[i].first + p[j].first < 0){
            u.push_back(p[i].second);
            v.push_back(p[j].second);
            d.push_back(p[j].first);
            p[i].first += p[j].first;
            p[j].first = 0;
            j--;
        }
        else if(p[i].first + p[j].first > 0){
            u.push_back(p[i].second);
            v.push_back(p[j].second);
            d.push_back(-p[i].first);
            p[j].first += p[i].first;
            p[i].first = 0;
            i++;
        }
        else{
            if(p[i].first == 0){
                i++;
                j--;
                continue;
            }
            u.push_back(p[i].second);
            v.push_back(p[j].second);
            d.push_back(p[j].first);
            p[i].first = 0;
            p[j].first = 0;
            i++;
            j--;
        }
    }
    int l = u.size();
    cout << l << endl;
    for(int i = 0; i < l; i++) cout << u[i] + 1 << " " << v[i] + 1 << " " << d[i] << endl;
}