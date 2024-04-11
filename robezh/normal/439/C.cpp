#include <bits/stdc++.h>
using namespace std;

int n,k,ke,ko;
int num[100500];
vector<int> Vo, Ve;
vector<int> res[100500];


int main(){
    int odd = 0, even = 0;
    scanf("%d%d%d", &n, &k, &ke);
    ko = k - ke;
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        if(num[i]%2) odd++, Vo.push_back(num[i]);
        else even++, Ve.push_back(num[i]);
    }
    if(odd < ko || odd%2 != ko%2 || (odd - ko)/2 + even < ke) return !printf("NO");


    int pos = 0;
    for(int i = 0; i < ko; i++){res[i].push_back(Vo.back()); Vo.pop_back();}
    for(pos = ko; pos < min(ko+(odd-ko)/2, ko+ke); pos++){
        res[pos].push_back(Vo.back()); Vo.pop_back();
        res[pos].push_back(Vo.back()); Vo.pop_back();
    }
    for(;pos < ko+ke; pos++){
        res[pos].push_back(Ve.back()), Ve.pop_back();
    }
    while(!Ve.empty()){
        res[0].push_back(Ve.back()), Ve.pop_back();
    }
    while(!Vo.empty()){
        res[0].push_back(Vo.back()), Vo.pop_back();
    }
    printf("YES\n");
    for(int i = 0; i < k; i++){
        printf("%d ", res[i].size());
        for(int x : res[i]) printf("%d ", x);
        printf("\n");
    }



}