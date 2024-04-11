#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int N, M;
int anim[100005];
vector< pair<int, int> > locs;
vector<int> adj[100005];

int P[100005];
int R[100005];
int S[100005];

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

int main(){
    cin >> N >> M;
    init(N);
    
    for(int i=0; i<N; i++){
        cin >> anim[i];
        locs.push_back(make_pair(anim[i], i));
    }
    
    sort(locs.begin(), locs.end());

    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        adj[A-1].push_back(B-1);
        adj[B-1].push_back(A-1);
    }    
    
    
    double tot = 0;
    
    for(int i=locs.size()-1; i>=0; i--){
        int node = locs[i].second;
        long long nims = locs[i].first;
    
        set<long long> fams;
        
        long long comb = S[rep(node)];
        fams.insert(rep(node));
        
        for(int j=0; j<adj[node].size(); j++)
            if(anim[adj[node][j]]>=nims && !fams.count(rep(adj[node][j]))){
                comb += S[rep(adj[node][j])];
                fams.insert(rep(adj[node][j]));
            }

        for(set<long long>::iterator it = fams.begin(); it!=fams.end(); it++){
            long long in_here = S[rep(*it)];
            long long out_there = comb - in_here;
            tot += in_here * out_there * nims;
        }
        
        for(set<long long>::iterator it = fams.begin(); it!=fams.end(); it++)
            unio(node, *it);
    }
    
    double pairs = ((long long)N) * (N-1LL);
    cout << tot/pairs << endl;

    return 0;
}