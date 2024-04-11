#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e5 + 500, mod = (int)1e9 + 7;

int n,q;
vector<P> qry[N];
int num[N];
bool S[(1 << 20) + 50];
vector<int> Sv;
int cur = 1;
int res[N];

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    for(int i = 0; i < q; i++){
        int l, x;
        scanf("%d%d", &l, &x);
        l--;
        qry[l].push_back({x, i});
    }
    Sv.push_back(0);
    S[0] = true;
    for(int i = 0; i < n; i++){
        if(S[num[i]]) cur = (cur * 2) % mod;
        else {
            vector<int> ls;
            for(int x : Sv) ls.push_back(x ^ num[i]);
            for(int x : ls){Sv.push_back(x); S[x] = true;}
        }
        for(auto p : qry[i]){
            if(S[p.first]) res[p.second] = cur;
            else res[p.second] = 0;
        }
    }
    for(int i = 0; i < q; i++){
        printf("%d\n", res[i]);
    }
}