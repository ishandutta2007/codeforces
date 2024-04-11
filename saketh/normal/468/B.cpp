#include <iostream>
#include <map>
using namespace std;

long long N, A, B;
long long v[100005];
map<long long, int> ri;

int ans[100005];
int a_adj[100005];
int b_adj[100005];

bool dfs(int i){
    if(i == -1) return true;

    if(ans[i]) return true;
    if(a_adj[i]!=-1 && (ans[a_adj[i]] == 0)){
        ans[a_adj[i]] = 1;
        ans[i] = 1;
        return dfs(b_adj[a_adj[i]]);
    }
    else if(b_adj[i]!=-1 && (ans[b_adj[i]] == 0)){
        ans[i] = 2;
        ans[b_adj[i]] = 2;
        return dfs(a_adj[b_adj[i]]);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> A >> B;
    for(int i=0; i<N; i++){
        cin >> v[i];
        ri[v[i]] = i;
    }

    if(A == B){
        bool fine = true;
        for(int i=0; i<N; i++)
            fine &= ri.count(A - v[i]);
        if(fine){
            cout << "YES" << endl;
            for(int i=0; i<N; i++)
                cout << 0 << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
        return 0;
    }
    
    bool good = true;

    for(int i=0; i<N; i++){
        a_adj[i] = b_adj[i] = -1;
        if(ri.count(A - v[i])) 
            a_adj[i] = ri[A - v[i]];
        if(ri.count(B - v[i])) 
            b_adj[i] = ri[B - v[i]];

        if(a_adj[i] == -1 && b_adj[i] == -1)
            good = false;
    }

    for(int i=0; i<N; i++)
        if(a_adj[i] == -1 || b_adj[i] == -1)
            good &= dfs(i);

    for(int i=0; i<N; i++)
        good &= dfs(i);

    if(!good){ cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    for(int i=0; i<N; i++)
        cout << ans[i]-1 << " ";
    cout << endl;
    return 0;

}