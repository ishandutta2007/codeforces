#include <iostream>
#include <vector>
using namespace std;

int N, M;
int qt[100005], qv[100005][2];
bool qf[100005];

int wd[100005], did = 0;
vector<pair<int, int> > req[100005];
vector<int> que[100005];

bool has_boss[100005], vis[100005];
vector<int> sub[100005];

void dfs(int loc){
    vis[loc] = true;
    for(int i=0; i<req[loc].size(); i++)
        if(!vis[req[loc][i].first])
            qf[req[loc][i].second] = true;
    
    for(int i=0; i<sub[loc].size(); i++)
        dfs(sub[loc][i]);
    vis[loc] = false;
}


int P[250005], R[250005], S[250005];

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
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> qt[i];
        cin >> qv[i][0];
        qv[i][0]--;
        
        if(qt[i] != 2){
            cin >> qv[i][1];
            qv[i][1]--;

            if(qt[i] == 1){
                has_boss[qv[i][0]] = true;
                sub[qv[i][1]].push_back(qv[i][0]);
            }
            else{
                req[wd[qv[i][1]]].push_back(make_pair(qv[i][0], i));
                que[qv[i][1]].push_back(i);
            }
        }
        else{
            wd[did++] = qv[i][0];
        }
    }

    for(int i=0; i<N; i++)
        if(!has_boss[i])
            dfs(i);

    init(N);

    int wdoc = 0;
    for(int i=0; i<M; i++){
        if(qt[i] == 1) unio(qv[i][0], qv[i][1]);
        if(qt[i] == 2){
           for(int j=0; j<que[wdoc].size(); j++){
               int qi = que[wdoc][j];
               qf[qi] |= rep(wd[qv[qi][1]]) != rep(qv[qi][0]);
           }
           wdoc++;
        }    
    }

    for(int i=0; i<M; i++)
        if(qt[i] == 3)
            cout << (qf[i]?"NO":"YES") << "\n";
    cout.flush();
    return 0;
}