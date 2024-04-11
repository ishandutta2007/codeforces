#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 8000000;
int N, M, K, sc[55][55];
string a, b;

int ctoi(char c){ return (c>='a')?(c-'a'):(c-'A'+26); }
char itoc(int i){ return (i>=26)?(i-26+'A'):(i+'a'); }

int main(){
    ios_base::sync_with_stdio(false);
    cin >> K >> N >> a >> b;    
    M = N;    

    for(int i=0; i<K; i++)
        sc[ctoi(a[i])+1][ctoi(b[i])+1]--;

    vector<int> u(N+1), v(M+1), p(M+1), way(M+1);

    for(int i=1; i<=N; i++){
        p[0] = i;
        int j0 = 0;
    
        vector<int> minv(M+1, INF);
        vector<char> used(M+1, false);
        
        do{
            used[j0] = true;
            int i0 = p[j0], delta = INF,  j1;
            for(int j=1; j<=M; j++)
                if(!used[j]){
                    int cur = sc[i0][j] - u[i0] - v[j];
                    if(cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta)
                        delta = minv[j], j1 = j;
                }

            for(int j=0; j<=M; j++)
                if(used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
    
        do{
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    vector<int> ans (N+1);
    for(int j=1; j<=M; j++)
        ans[p[j]] = j;

    int tot = 0;
    for(int i=1; i<=N; i++)
        tot -= sc[i][ans[i]];
    
    cout << tot << endl;  
    for(int i=1; i<=N; i++)
        cout << itoc(ans[i]-1);
    cout << endl;
    return 0;
}