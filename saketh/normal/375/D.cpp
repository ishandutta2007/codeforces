#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <string.h>
using namespace std;

const int MAXN = 100005;

struct vert{
    int N, A;
    int *bit;
    unordered_map<int, int> *cc;

    vert(int SIZE, int ALLOC){
        N = SIZE;
        A = ALLOC;
        bit = (int *)calloc(ALLOC+1, sizeof(int));
        cc = new unordered_map<int, int>();
    }

    int read(int k){
        int sum = 0;
        while(k > 0){ sum += bit[k]; k -= (k & -k); }
        return sum;
    }

    void update(int i, int v=1){
        while(i <= A){ bit[i]+=v; i += (i & -i); }
    }
};

int N, M, color[MAXN], ts[MAXN], bc[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int> > que[MAXN];
int ans[MAXN];

int prec(int loc = 0, int par = -1){
    ts[loc] = 1;
    for(int nbr : adj[loc]){
        if(nbr == par) continue;
        int size = prec(nbr, loc);
        ts[loc] += size;
        bc[loc] = max(bc[loc], size);
        
    }
    return ts[loc];
}

vert *calc(int loc = 0, int par = -1, int end = MAXN){
    vector<vert*> child;

    int ms = 0;
    vert *big = NULL;
    bool found = false;

    for(int nbr : adj[loc]){
        if(nbr == par) continue;

        if(!found && ts[nbr] == bc[loc]){
            found = true;
            child.push_back(calc(nbr, loc, end));
            big = child.back();
        }            
        else child.push_back(calc(nbr, loc, ts[nbr]));
    }

    unordered_map<int,int> *bcc;
    
    if(big == NULL){
        big = new vert(0, end);
        bcc = big->cc;
    }
    else{
        bcc = big->cc;
        for(vert *ch : child){
            if(ch == big) continue;
            big->N += ch->N;
            for(pair<int, int> e : *(ch->cc)){
                if(bcc->count(e.first))
                    big->update((*bcc)[e.first], -1);
                (*bcc)[e.first] += e.second;
                big->update((*bcc)[e.first], 1);
            }  
            free(ch->cc);
            free(ch->bit);
            free(ch);
        }
    }

    big->N++;    
    if(bcc->count(color[loc]))
        big->update((*bcc)[color[loc]], -1);
    (*bcc)[color[loc]]++;
    big->update((*bcc)[color[loc]], 1);

    for(pair<int, int> &q : que[loc]){
        if(q.first > big->N) continue;
        ans[q.second] = big->read(big->N);
        if(q.first > 1) ans[q.second] -= big->read(q.first-1);
    }

    return big;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> color[i];
    for(int i=1; i<N; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b; a--;
        que[a].emplace_back(b, i);
    }
    
    prec();
    calc();

    for(int i=0; i<M; i++)
        cout << ans[i] << "\n";
    cout.flush();
    return 0;
}