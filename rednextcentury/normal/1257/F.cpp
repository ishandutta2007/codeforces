#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define ms multiset
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //uid<int> u1(5, 10); u1(rnd);
 
int main() {
    fast;
    int a; scanf("%d", &a);
    uset<int> s;
    for(int q=0; q<a; q++){
        unsigned int x;
        scanf("%u", &x);
        s.insert(x);
    }
    a = s.size();
    unsigned int m[a];
    unsigned int cnt = 0;
    for(auto &i : s) m[cnt++] = i;
    shuffle(m, m+a, rnd);
    unsigned int g = (1<<30);
    for(unsigned int c = 0; c<g; c++){
        unsigned int ans = __builtin_popcount(c^m[0]);
        for(auto &i : m){
            if(__builtin_popcount(c^i)!=ans){
                ans = -1;
                break;
            }
        }
        if(ans!=-1){
            cout<<c;
            return 0;
        }
    }
    cout<<-1;
}