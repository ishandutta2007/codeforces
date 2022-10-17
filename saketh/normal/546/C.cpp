#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;

typedef long long ll;

int N, k, v;
deque<int> a, b;
unordered_set<ll> seen;

bool cycle(){
    ll s = 0;
    s = a.size();
    for(int v : a)
        s = 10 * s + v;
    for(int v : b)
        s = 10 * s + v;
    if(seen.count(s)) return true;
    seen.insert(s);
    return false;
}

int main(){
    cin >> N;

    for(cin >> k; k; k--){
        cin >> v;
        a.push_back(v-1);
    }

    for(cin >> k; k; k--){
        cin >> v;
        b.push_back(v-1);
    }

    int S = 0;

    for(;a.size() && b.size(); S++){
        if(a.front() < b.front()){
            b.push_back(a.front());
            a.pop_front();
            b.push_back(b.front());
            b.pop_front();
        }
        else{
            a.push_back(b.front());
            b.pop_front();
            a.push_back(a.front());
            a.pop_front();
        }

        if(cycle()){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << S << " " << (a.size() ? 1 : 2) << endl;
}