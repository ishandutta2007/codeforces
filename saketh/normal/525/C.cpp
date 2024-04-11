#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

int N, S;
map<ll, ll> st;
vector<ll> prs;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> S;
        st[-S]++;
    }

    ll pct = 0, prv = 1ll << 50;

    for(auto p : st){
        ll L = -p.first;
        ll C = p.second;

        if(prv != L+1) pct = 0;

        while(pct >= 1 && C >= 1){
            prs.push_back(L);
            pct--;
            C--;
        } 

        while(C >= 2){
            prs.push_back(L);
            C-=2;
        }

        pct = C;
        prv = L;
    }

    ll ans = 0;
    for(int i=0; i+1<prs.size(); i+=2){
        ans += prs[i] * prs[i+1];
    }

    cout << ans << endl;
}