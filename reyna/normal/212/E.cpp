//
//  212E.cpp
//
//  Created by arash mahmoudian on 11/10/14.
//  Copyright (c) 2014 arash mahmoudian. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 12345;
vector<int> al[maxn];
vector<int> arr;
int canGet[maxn];
bool ans[maxn];
int n;

int dfs(int v,int p,int par){
//  cerr << v << endl;
    int ret = 1;
    for(int i = 0; i < al[v].size();i++){
        int u = al[v][i];
        if(u == p)
            continue;
        int tmp = dfs(u,v,par);
        ret+=tmp;
        if(v == par){
            arr.push_back(tmp);
        }
    }
    if(v == par){
        cerr << "<" <<v <<endl;
        canGet[0] = 1;
        for(int i = 0; i < arr.size();i++){
            for(int j = n-1; j > -1;j--){
                if(canGet[j]){
                    canGet[j+arr[i]] = 1;
                }
            }
        }
        for(int i = 1; i < n-1;i++){
            if(canGet[i]){
                ans[i] = true;
                ans[n-i-1] = true;
            }
            canGet[i] = 0;
        }
        canGet[0] = 0;
        canGet[n-1] = 0;
        for(int i = 0; i < arr.size();i++){
            cerr << arr[i] << "!" << endl;
        }
        arr.clear();
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1;i++){
        int u,v;
        cin >> u >> v;
        al[--u].push_back(--v);
        al[v].push_back(u);
    }
    for(int i = 0; i < n;i++){
        dfs(i,-1,i);
        cerr << "End" << endl;
    }
    int cnt = 0;
    for(int i = 0; i < n;i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < n;i++){
        if(ans[i]){
            cout << i << ' ' << n-i-1 << endl;
        }
    }
    return 0;
}