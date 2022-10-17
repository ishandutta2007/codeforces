#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll A, B, bd = -(1LL << 50), ap, bp;
vector<ll> t1, t2;

ll pts(vector<ll> &s, ll cut){
    auto a = upper_bound(s.begin(), s.end(), cut);
    return (a - s.begin()) * 2LL + (s.end() - a) * 3LL;
}

void try_cut(ll cut){
    ll p1 = pts(t1, cut), p2 = pts(t2, cut);
    if(p1 - p2 > bd){
        bd = p1 - p2;
        ap = p1;
        bp = p2;
    }
    else if((p1 - p2 == bd) && (p1 > ap)){
        ap = p1;
        bp = p2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> A;
    for(int i=0; i<A; i++){
        ll v; cin >> v;
        t1.push_back(v);
    }

    cin >> B;
    for(int i=0; i<B; i++){
        ll v; cin >> v;
        t2.push_back(v);
    }

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());

    for(int i=0; i<t1.size(); i++)
        try_cut(t1[i] - 1);
    try_cut(1LL << 50);

    cout << ap << ":" << bp << endl;
    return 0;
}