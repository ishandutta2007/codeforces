#include <bits/stdc++.h>
using namespace std;

int n, a;
vector<int> num;
const int INF = (int)1e9 + 500;

int get(vector<int> V){
    if(V.empty()) return 0;

    vector<int> ano;
    ano.clear();
    int mn = INF;
    for(int x : V) mn = min(mn, x);
    int res = mn;
    for(int i = 0; i < V.size(); i++){
        if(V[i] >= mn+1) ano.push_back(V[i]-mn);

        if(i == V.size()-1 || V[i+1] == mn){
            res += get(ano);
            if(res > (int)V.size()) return V.size();
            ano.clear();
        }
    }
    //res = min((int)V.size(), res);
    return res;
}

int main(){
    cin >> n;
    int add = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        num.push_back(a);
    }

    cout << get(num) + add;
}