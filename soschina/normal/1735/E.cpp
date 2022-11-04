#include <cstdio>
#include <cmath>
#include <set>
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
const int N = 1001;

int t, n, d[2][N];

set<int> mem;
bool chk(int dist){
    if(mem.find(dist) != mem.end())
        return false;
    mem.insert(dist);
    multiset<int, greater<int>> st[2];
    vector<int> ans;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            st[i].insert(d[i][j]);
    while(st[0].size() && max(*st[0].begin(), *st[1].begin()) > dist){
        if(*st[0].begin() > *st[1].begin()){
            int x = *st[0].begin() - dist;
            auto it = st[1].find(x);
            if(it == st[1].end())
                return false;
            st[1].erase(it);
            st[0].erase(st[0].begin());
            ans.push_back(x + dist);
        }
        else{
            int x = *st[1].begin() - dist;
            auto it = st[0].find(x);
            if(it == st[0].end())
                return false;
            st[0].erase(it);
            st[1].erase(st[1].begin());
            ans.push_back(-x);
        }
    }
    if(st[0].size()){
        auto it0 = st[0].begin();
        auto it1 = --st[1].end();
        while(true){
            if(*it0 + *it1 != dist)
                return false;
            ans.push_back(*it0);
            it0++;
            if(it0 == st[0].end())
                break;
            it1--;
        }
    }
    int delta = 0;
    for(int x : ans)
        if(x < delta)
            delta = x;
    delta = -delta;
    for(int x : ans)
        if(x + delta > 2e9)
            return false;
    if(delta + dist > 2e9)
        return false;
    puts("YES");
    for(int x : ans)
        printf("%lld ", x + delta);
    printf("\n%lld %lld\n", delta, delta + dist);
    return true;
}

signed main(){
    scanf("%lld", &t);
    while(t--){
        mem.clear();
        scanf("%lld", &n);
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lld", &d[i][j]);
        bool flag = false;
        for (int j = 1; j <= n && !flag; j++){
            if(chk(abs(d[0][1] - d[1][j])))
                flag = true;
            else if(chk(d[0][1] + d[1][j]))
                flag = true;
        }
        if(!flag)
            puts("NO");
    }
	return 0;
}