#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

// start: 2feb924109507119d3da1584e7e1c7d2  -
struct union_find {
    vector<int> P, R, S;
    
// 		start: f3d026d4b4e6b58f158e77cfe9db65d7  -
    union_find (int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
    }
    
    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }
// 		end

// 		start: 953d810382f20fe63d56d0468f8db407  -
    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) return false;
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
// 		end
};
// end


int N;
int ht[MAXN];
bool app[MAXN];
vector<pair<int, int> > bears;
vector<pair<int, int> > pf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> ht[i];
        bears.emplace_back(ht[i], i);
    }

    sort(bears.begin(), bears.end());

    union_find uf(N);

    pf.emplace_back(0x7f7f7f7f, 0);
    for(int i=N-1; i>=0; i--){
        int idx = bears[i].second;
        app[idx] = true;
        if(idx>0 && app[idx-1]) uf.unio(idx, idx-1);
        if(idx<N-1 && app[idx+1]) uf.unio(idx, idx+1);
        int wid = uf.S[uf.rep(idx)];
        if(pf.back().first == bears[i].first)
            pf.back().second = max(pf.back().second, wid);
        else pf.emplace_back(bears[i].first, wid);
    }    

    vector<int> ans;
    for(int i=1, j=0; i<=N; i++){
        while(pf[j].second < i) j++;
        cout << pf[j].first << " ";
    }
    cout << endl;
}