#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n,m,a;
string s;
vector<int> at, df;
int cd[N];

int del_all(){
    multiset<int> A, C;
    //for(int x : df) D.insert(x);
    for(int i = 0; i < m; i++) C.insert(cd[i]);
    //for(int a : at) A.insert(a);

    int res = 0;


    for(int x : df){
        if(C.empty()) return 0;
        auto it = C.upper_bound(x);
        if(it == C.end()) return 0;
        C.erase(it);
    }
    for(int x : at){
        if(C.empty()) return 0;
        auto it = C.lower_bound(x);
        if(it == C.end()) return 0;
        res += (*it - x);
        C.erase(it);
    }
    for(int x : C) res += x;
    return res;
}

int greedy_all(){
    int res = 0;
    for(int i = m - 1, j = 0; i >= 0 && j < at.size(); i--, j++){
        res += max(0, cd[i] - at[j]);
    }
    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s >> a;
        if(s[0] == 'A') at.push_back(a);
        else df.push_back(a);
    }
    for(int i = 0; i < m; i++) cin >> cd[i];
    sort(df.begin(), df.end());
    sort(at.begin(), at.end());
    sort(cd, cd+m);
    printf("%d", max(del_all(), greedy_all()));




}