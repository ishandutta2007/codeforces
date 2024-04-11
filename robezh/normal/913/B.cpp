#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> V[1005];

bool check_single(int i){
    if(V[i].size() == 0) return true;
    int cnt = 0;
    for(int j = 0; j < V[i].size(); j++){
        if(V[V[i][j]].size() == 0) cnt++;
    }
    return cnt >= 3;
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(!check_single(i)) return false;
    }
    return true;
}

int main() {
    cin >> n;
    int tmp;
    for(int i = 2; i <= n; i++){
        cin >> tmp;
        V[tmp].push_back(i);
    }
    if(check()) printf("Yes");
    else printf("No");

}