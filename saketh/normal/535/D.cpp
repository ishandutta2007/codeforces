#include <iostream>
#include <vector>
using namespace std;

int N, M;
string p;
int lp[1000005];
bool ol[1000005];
vector<int> occ;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> p;
    occ.resize(M);
    for(int &x : occ) cin >> x;

    lp[0] = -1;    
    for(int l=1; l<=p.size(); l++){
        lp[l] = lp[l-1];
        while(lp[l] != -1 && p[lp[l]] != p[l-1])
            lp[l] = lp[lp[l]];
        lp[l]++;
    }

    ol[0] = true;
    for(int l=p.size(); l>0; l=lp[l]){
        ol[l] = true;
    }

    if(M){
        N -= p.size();
        int prv = occ[0];
        
        for(int i=1; i<M; i++){
            int ov = max(0, int(p.size()) - occ[i] + prv);
            if(!ol[ov]){ cout << 0 << endl; return 0; }
            prv = occ[i];
            N -= p.size() - ov;
        }
    }

    long long res = 1;
    for(int i=0; i<N; i++)
        res = (26 * res) % 1000000007;
    cout << res << endl;
}