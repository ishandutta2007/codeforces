#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> adj[100005];
bool black[100005];
int white_cache[100005];

bool is_white(int loc, int par){
   if(white_cache[loc] != -1) return white_cache[loc];
   bool children = true;
   for(int i=0; i<adj[loc].size(); i++)
       if(adj[loc][i] == par) continue;
       else children &= is_white(adj[loc][i], loc);
   return white_cache[loc] = (children && !black[loc]);
}

long long mod_pow(long long base, long long exp){
    if(exp == 0) return 1;
    if(exp % 2) return (base * mod_pow((base * base) % 1000000007, exp/2)) % 1000000007;
    return mod_pow((base * base) % 1000000007, exp/2);
}

pair<long long, long long> calc(int loc, int par){
    if(is_white(loc, par)) return make_pair(0, 1);

    vector<pair<long long, long long> > childs;
    for(int i=0; i<adj[loc].size(); i++)
        if(adj[loc][i] == par || is_white(adj[loc][i], loc)) continue;
        else childs.push_back(calc(adj[loc][i], loc));

    long long all_cut = 1;
    for(int i=0; i<childs.size(); i++){
        long long sum = (childs[i].first + childs[i].second) % 1000000007;
        all_cut = (all_cut * sum) % 1000000007;
    }

    if(black[loc]) return make_pair(all_cut, 0);

    long long not_all = 0;
    for(int i=0; i<childs.size(); i++){
        long long inv = mod_pow((childs[i].first + childs[i].second) % 1000000007, 1000000005);
        long long div = (all_cut * inv) % 1000000007;
        long long val = (div * childs[i].first) % 1000000007;
        not_all = (not_all + val) % 1000000007;
    }

    return make_pair(not_all, all_cut);
}

int main(){
    cin >> N;
    for(int i=1; i<N; i++){
        cin >> T;
        adj[i].push_back(T);
        adj[T].push_back(i);
    }

    for(int i=0; i<N; i++){
        cin >> black[i];
        white_cache[i] = -1;
    }

    cout << calc(0, -1).first << endl;
    return 0;
}