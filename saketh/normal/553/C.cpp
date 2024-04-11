#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100100;

int P[MAXN];
int R[MAXN];
int S[MAXN];

void init(int N){
    for(int i=0; i<N; i++){
        P[i] = i;
        R[i] = 0;
        S[i] = 1;
    }
}

int rep(int i){
    if(P[i] != i) P[i] = rep(P[i]);
    return P[i];
}

bool unio(int a, int b){
    a = rep(a);
    b = rep(b);
    if(a == b) return false;
    if(R[a] < R[b]){
        P[a] = b;
        S[b] += S[a];
    }
    else{
        P[b] = a;
        S[a] += S[b];
    }
    if(R[a] == R[b]) R[a]++;
    return true;
}

int N, M;
vector<pair<int, int> > edge;
vector<int> hate[MAXN];

int which[MAXN];
int uniq[MAXN];
vector<int> comp[MAXN];

int main(){
    setup();
    cin >> N >> M;
    init(N);

    int CC = N;

    for(int i=0; i<M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        if(C){
            CC -= unio(A, B);            
        }
        else{
            edge.emplace_back(A, B);
        }
    }

    int UU = 1;
    for(int i=0; i<N; i++){
        if(!uniq[rep(i)])
            uniq[rep(i)] = UU++;
    }

    for(auto p : edge){
        int A = uniq[rep(p.first)]-1;
        int B = uniq[rep(p.second)]-1;
        hate[A].push_back(B);
        hate[B].push_back(A);
    }

    int id = 1;
    unordered_map<int, int> dist;

    for(int i=0; i<UU-1; i++){
        if(which[i]) continue;
        which[i] = id;

        comp[id].push_back(i);
        dist.clear();
           
        int src = comp[id].front();
        queue<pair<int, int> > bfs;
        bfs.push({src, 0});        
        dist[src] = 0;

        while(!bfs.empty()){
            int loc = bfs.front().first;
            int far = bfs.front().second;
            bfs.pop();

            for(int nbr : hate[loc])
                if(!dist.count(nbr)){
                    which[nbr] = id;
                    comp[id].push_back(nbr);
                    dist[nbr] = far+1;
                    bfs.push({nbr, far+1});
                }
        }

        for(int a : comp[id]){
            for(int n : hate[a]){
                int d1 = dist[a];
                int d2 = dist[n];
                if(d1%2 == d2%2){ 
                    cout << 0 << endl; 
                    return 0;
                }
            }
        }

        id++;
    }

    ll ans = 1;
    for(int i=2; i<id; i++)
        ans = (ans * 2) % 1000000007;
    cout << ans << endl;
}