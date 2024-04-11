#include <bits/stdc++.h>
using namespace std;

const int N = 505;
typedef pair<int, int> P;

int n, a[N];
vector<P> res;

int main(){
    cin >> n;
    int tot_d = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot_d += a[i];
    }
    if(tot_d < 2 * (n-1)) return !printf("NO");

    vector<int> one;
    vector<P> go;
    int prv = -1;
    for(int i = 0; i < n; i++){
        if(a[i] > 1) go.push_back({a[i], i});
        else one.push_back(i);
    }
    int dia = go.size() - 1 + min(2, (int)one.size());
    for(int i = 0; i < go.size() - 1; i++){
        res.push_back({go[i].second, go[i+1].second});
        a[go[i].second]--, a[go[i+1].second]--;
    }
    int cur = 0;
    if(one.size() >= 1){
        res.push_back({go.back().second, one[0]});
        a[go.back().second]--;
    }
    for(int i = 1; i < one.size(); i++){
        while(a[go[cur].second] == 0 && cur < go.size()) cur++;
        res.push_back({go[cur].second, one[i]});
        a[go[cur].second]--;
    }
    cout << "YES" << " " << dia << endl;
    cout << n - 1 << endl;
    for(auto p : res) cout << p.first + 1 << " " << p.second + 1 << endl;


}