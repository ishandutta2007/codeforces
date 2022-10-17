#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[3005];
int ct[3005];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;

        adj[A-1].push_back(B-1);
    }

    long long ans = 0;

    for(int a=0; a<N; a++){
        memset(ct, 0, sizeof(ct));

        for(int i=0; i<adj[a].size(); i++)
            for(int j=0; j<adj[adj[a][i]].size(); j++)
                ct[adj[adj[a][i]][j]]++;

        for(int i=0; i<3000; i++)
            if(i != a)
                ans += (ct[i] * (ct[i] - 1)) / 2;
    }

    cout << ans << endl;
    cout.flush();
    return 0;
}