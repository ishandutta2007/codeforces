#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unordered_map<int, ll> map;

int N, V;
map r, a, b;

ll gcd(ll x, ll y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> V;
        for(auto &x : a)
            b[gcd(x.first, V)] += x.second;
        b[V]++;
        
        swap(a, b);    
        b.clear();
        for(auto &x : a)
            r[x.first] += x.second;
    }

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V;
        cout << r[V] << "\n";
    }
    cout.flush();
    return 0;
}