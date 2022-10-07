#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int p[200009];
int P[2000009];
int f[2000009];
int F[2000009];
vector<int> V[2000009];
long long sc = 0;
void fa(int x, int ty){
    int s = 1;
    int y = x;
    while(x > 1){
            int z = P[x];
            int k = 0;
            while(x % z == 0){
                x /= z;
                k++;
            }
            if(ty){
                if(V[z].size() == 1 || (V[z].size() > 1 &&k > V[z][V[z].size()-2]))
                    s = 0;
            }
            else{
                if(F[z] < k) F[z] = k;
                V[z].push_back(k);
            }
        }
    if(s && ty) sc = 1;
}
main(){
    int n;
    cin >> n;
    for(int i = 2; i <= 2e6; i++){
        if(P[i] == 0){
            for(int j = i; j <= 2e6; j+=i)
                P[j] = i;
        }
    }
    for(int i = 0; i < n; i++){
        cin >>p[i];
        f[p[i]]++;
    }

    long long ans = 1;
    vector<int> t;

    for(int i = 2e6; i >= 1; i--){
        if(f[i] == 0) continue;
        if(f[i] >= 3) sc = 1;
        if(f[i] >= 2){
            t.push_back(i);
            t.push_back(i-1);
            fa(i,0);
            fa(i-1,0);
            continue;
        }
        if(F[i]) fa(i-1,0),t.push_back(i-1);
        else fa(i,0),t.push_back(i);
    }

    for(int i = 0; i <= 2e6; i++)
        sort(V[i].begin(),V[i].end());
    for(int i = 0; i < t.size(); i++){
        fa(t[i],1);
    }
    for(int i = 0; i <= 2e6; i++){
        for(int j = 0; j < F[i]; j++)
            ans = ans * (long long)i % mod;
    }
    if(sc) ans = (ans + 1) % mod;
    cout << ans << endl;

}