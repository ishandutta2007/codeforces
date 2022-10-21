#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int S,B;
    cin >> S >> B;
    vector<P> enemy(B);
    vector<P> team(S);
    for(int i=0;i<S;i++){
        int a;
        cin >> a;
        team[i] = {a,i};
    }
    for(int i=0;i<B;i++){
        int g,d;
        cin >> d >> g;
        enemy[i] = {d,g};
    }
    sort(team.begin(),team.end());
    sort(enemy.begin(),enemy.end());
    int id = 0;
    vector<ll> ans(S);
    ll res = 0;
    for(int i=0;i<S;i++){
        while(id<B && enemy[id].first<=team[i].first){
            res += enemy[id].second;
            id++;
        }
        ans[team[i].second] = res;
    }
    for(auto x:ans) cout << x << " ";
    cout << endl;
}