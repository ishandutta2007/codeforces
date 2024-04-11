#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

pii days[MAX_N];
int n, m, k;
set<int> adj[MAX_N];

int cnt;

bool in[MAX_N];
int fr[MAX_N];
queue<int> toProcess;
void process(bool first){
    if(first){
        for(int i=1; i<=n; i++){
            if(fr[i] < k && in[i]){
                toProcess.push(i);
            }
        }
    }

    while(!toProcess.empty()){
        int top = toProcess.front();
        toProcess.pop();
        if(!in[top]) continue;

        in[top] = false;
        cnt--;

        //set<int> toErase;
        for(set<int>::iterator it = adj[top].begin(); it != adj[top].end(); it++){
            int other = *it;
            if(in[other]){
                fr[other]--;
                if(fr[other] < k){
                    toProcess.push(other);
                }
                
                adj[other].erase(top);
            }/* else{
                toErase.insert(other);
            }*/
        }

        /*for(auto u : toErase){
            adj[top.second].erase(u);
        }*/
    }
}


int answers[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    cnt = n;

    for(int i=0; i<m; i++){
        cin >> days[i].first >> days[i].second;
        adj[days[i].first].insert(days[i].second);
        adj[days[i].second].insert(days[i].first);
        fr[days[i].first]++;
        fr[days[i].second]++;
    }

    memset(in, true, sizeof in);
    process(true);

    /*for(int i=1; i<=n; i++){
        if(in[i]){
            cout << i << " has " << fr[i] << " friends on trip\n";
        }
    }*/

    answers[m] = cnt;

    for(int i=m-1; i>=0; i--){
        //cout << "day " << i << "\n";
        pii ripf = days[i];
        if(!in[ripf.first] || !in[ripf.second]){
            answers[i] = cnt;
            //cout << "this was useless lmao\n";
            continue;
        }
        /*fr[ripf.first]--;
        fr[ripf.second]--;
        if(fr[ripf.first] < k || fr[ripf.second] < k){
            process();
        }*/
        if(fr[ripf.first] <= k || fr[ripf.second] <= k){
            if(fr[ripf.first] <= k){
                toProcess.push(ripf.first);
            }
            if(fr[ripf.second] <= k){
                toProcess.push(ripf.second);
            }

            process(false);
        } else{
            fr[ripf.first]--;
            fr[ripf.second]--;
            adj[ripf.first].erase(ripf.second);
            adj[ripf.second].erase(ripf.first);
        }

        answers[i] = cnt;

        /*for(int i=1; i<=n; i++){
            if(in[i]){
                cout << i << " has " << fr[i] << " friends on trip\n";
            }
        }*/
    }

    //cout << cnt << "\n";

    for(int i=1; i<=m; i++){
        cout << answers[i] << "\n";
    }

    return 0;
}