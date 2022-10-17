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

const int MAXN = 2e5 + 100;

int N, M;

vector<int> adj[MAXN];
int v1[MAXN];
int v2[MAXN];
int fc[MAXN];
int ori[MAXN];

int tot[MAXN];

int main(){
    setup();
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> v1[i] >> v2[i] >> fc[i];
        v1[i]--, v2[i]--;
        adj[v1[i]].push_back(i);
        adj[v2[i]].push_back(i);
        tot[v1[i]] += fc[i];
        tot[v2[i]] += fc[i];
    } 

    tot[0] = 0;
    for(int i=1; i<N; i++)
        tot[i] /= 2;
    tot[N-1] = 0;

    queue<int> zero; 
    zero.push(0);

    while(!zero.empty()){
        int loc = zero.front();
        zero.pop();

        for(int e : adj[loc]){
            if(!ori[e]){
                ori[e] = (v1[e] == loc) ? 1 : 2;
                int nbr = v1[e] + v2[e] - loc;
                tot[nbr] -= fc[e];
                if(tot[nbr] == 0) zero.push(nbr); 
            }
        }
    }

    for(int i=0; i<M; i++)
        cout << ori[i]-1 << "\n";
}