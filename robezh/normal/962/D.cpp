#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

//struct P{
//    ll first;
//    int second;
//    P(ll f, int s){
//        first = f, second = s;
//    }
//    bool operator < (const P &a) const{
//        return first == a.first ? second  : first < a.first;
//    }
//};

int n;
priority_queue<P, vector<P>, greater<P> > pque;
ll num[150050];

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        pque.push(P(num[i], i));
    }
    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        if(pque.empty()) break;
        if(pque.top().first != p.first) continue;

        P p2 = pque.top(); pque.pop();
        num[p2.second] = 2*p2.first;
        num[p.second] = 0;
        pque.push(P(2*p2.first, p2.second));
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += (num[i] != 0);
    cout << cnt << endl;
    for(int i = 0; i < n; i++) if(num[i] != 0) cout << num[i] << " ";
}