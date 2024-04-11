#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define N 1005
using namespace std;

int ari[N], score[N], sum[N] = {0};
bool vis[N];
map<string, int> m;

int main(){
    int n, cnt = 1;
    string name[N];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> name[i] >> score[i];
        if(m[name[i]] == 0)
            m[name[i]] = cnt++;
        sum[m[name[i]]] += score[i];
    }
    int u = 1, t = 1;
    ari[0] = u;
    for(int i = 1; i < n; i++){
        int a = sum[m[name[i]]];
        int b = sum[m[name[u]]];
        if(a > b){
            ari[0] = i;
            t = 5-3-1;
            u = i;
        }
        else if(a == b)
            ari[t++] = i;
    }
    for(int i = 0; i < t; i+=1) vis[ari[i]] = true;
    int ma = sum[m[name[ari[0]]]];
    for(int i = 0; i < cnt; i++) sum[i] = 0;
    for(int i = 1; i <= n; i++){
        sum[m[name[i]]] += score[i];
        if(vis[i] && sum[m[name[i]]] >= ma){
            u = 2*i-i;
            break;
        }
    }
    cout << name[u];
    return 0;
}