#include<bits/stdc++.h>
using namespace std;
int al = 0;
long long f[109][109];
long long mod = 998244353;
long long F[266];
long long g[109][109][109];
int G(int a, int b, int c , int d){
    if(a < b && b < c&& c < d) return 24;
    if(a ==b && b == c && c == d) return 1;
    if(a ==b && b == c) return 4;
    if(b==c && c==d) return 4;
    if(a ==b && c == d) return 6;
    return 12;
}
int solve(vector<string> v){
    for(int i = 0; i < al; i++)
        for(int j = 0; j < al; j++)
            f[i][j] = 0;
    for(int i = 0; i < al; i++)
        for(int j = 0; j < al; j++)
            for(int k= 0; k < al; k++)
                g[i][j][k] = 0;
    for(int i = 0; i < v.size(); i++){
        int a = F[v[i][0]];
        int b = F[v[i].back()];
        string g = v[i]; reverse(g.begin(), g.end());
        if(g == v[i]) f[a][a]++;
        else f[a][b]++,f[b][a]++;
    }
    for(int i = 0; i < al; i++)
        for(int j = i; j < al; j++)
            for(int k = j; k < al; k++)
                for(int x = 0; x < al; x++){
                    g[i][j][k] = (g[i][j][k] + f[x][i] * f[x][j] * f[x][k]) % mod;}
    long long ans = 0;
    for(int i = 0; i < al; i++)
        for(int j = i; j < al; j++)
            for(int k = j; k < al; k++)
                for(int x = k; x < al; x++)
                    ans = (ans + g[i][j][k] * g[i][k][x] % mod * g[j][k][x] % mod * g[i][j][x] % mod * G(i,j,k,x) ) % mod;
    return ans;
}
vector<string> u[12];
map<string, bool> M;
main(){
    int n;
    cin >> n;
    for(int i = 'a'; i <= 'z'; i++)
        F[i] = al++;
    for(int i = 'A'; i <= 'Z'; i++)
        F[i] = al++;
    for(int i = '0'; i <= '9'; i++)
        F[i] = al++;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(),t.end());
        s = min(s, t);
        if(M[s]) continue;
        M[s] = 1;
        u[s.size()].push_back(s);
    }
    long long ans = 0 ;
    for(int i = 3; i <= 10; i++)
        ans = (ans + solve(u[i])) % mod;
    cout << ans << endl;
}