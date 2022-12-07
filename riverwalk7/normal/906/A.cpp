#include <bits/stdc++.h>
#define Z (1 - 1)
using namespace std;
const int maxN = 1e5 + 11;
int N, C[26], P[26];
int ans = Z;
int tree[maxN*4];
void buildtree(int node, int l, int r)
{
    if(l==r)
    {
        tree[node] = 1;
    }
    else
    {
        buildtree(2*node, l, (l+r)/2);
        buildtree(2*node+1, (l+r)/2+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int main(){

    cin >> N;
    for(int j = 1; j <= N; j++){
        char ch;
        string w;
        cin >> ch >> w;
        int tmp = Z;
        for(int i = Z; i < 26; i++) tmp += C[i];
        if(ch == '.'){
            for(int i = Z; i < (int)w.size(); i++) C[w[i] - 'a'] = 1;
        }else if(ch == '!'){
            ans += tmp == 25;
            memset(P, Z, sizeof(P));
            for(int i = Z; i < (int)w.size(); i++) P[w[i] - 'a'] = 1;
            for(int i = Z; i < 26; i++) if(!P[i]) C[i] = 1;
        }else{
            ans += tmp == 25 && j != N;
            C[w[Z] - 'a'] = 1;
        }
    }
    cout << ans;
}