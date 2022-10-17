#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef long long ll;

int N;
int s[205];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

bool vis[200];
vector<int> path;

pair<ll, ll> check(int l){
    memset(vis, 0, sizeof(vis));
    path.clear();

    for(int i=0; !vis[l]; i++){
        vis[l] = true;
        path.push_back(l);
        l = s[l];
    }

    for(int j=0; j<path.size(); j++)
        if(path[j] == l)
            return make_pair(j, path.size() - j);
    
    return make_pair(0, 0);
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s[i];
        s[i]--;
    }

    ll mv = 0;
    ll lc = 1;

    for(int i=0; i<N; i++){
        pair<ll, ll> p = check(i);
        
        lc = lcm(lc, p.second);
        mv = max(mv, p.first);
    }

    if(mv > lc){
        ll r = (mv + lc - 1) / lc;
        cout << r * lc << endl;
    }
    else cout << lc << endl;
}