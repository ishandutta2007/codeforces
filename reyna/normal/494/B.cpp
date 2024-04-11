//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Mod = 1e9 + 7;
const long long hMod = (long long)1000*1000*1000*1000*1000 + 7;
const int Maxn = 1e5 + 20;
const int Zarib = 43;
long long dp[Maxn];
int ptr[Maxn];
long long pw[Maxn];
long long sum[Maxn];
vector<int> Occ;
long long cal(int now,int n,int m){
//  cerr << now << "  " << ptr[now] << endl;
    if(dp[now] != -1)
        return dp[now];
    long long ret = 0;
    ret += cal(now+1,n,m);
    ret %= Mod;
    if(ptr[now] == Occ.size()){
        dp[now] = 1;
        sum[now] = sum[now+1] + 1;
        sum[now] %= Mod;
        return 0;
    }
    int Sum = m + Occ[ptr[now]];
//  cerr << now << " " << ptr[now] << " " << Sum << endl;
    ret += sum[Sum];
    ret += Mod;
    ret %= Mod;
    sum[now] = sum[now+1] + ret;
    sum[now] += Mod;
    sum[now] %= Mod;
//  cerr << now << " :) " << ret << " " << sum[Sum]<< endl;
    return dp[now] = ret % Mod;
}
int main(){
    pw[0] = 1;
    string S,P;
    cin >> S >> P;
    long long hp = 0;
    int n = S.length();
    int m = P.length();
    for(int i = 0; i < m;i++){
        hp *= Zarib;
        hp += P[i];
        hp %= hMod;
    }
    for(int i = 1; i < Maxn;i++){
        pw[i] = pw[i-1] * Zarib;
        pw[i] %= hMod;
    }
    long long hash = 0;
    for(int i = 0; i < m;i++){
        hash *= Zarib;
        hash += S[i];
        hash %= hMod;
    }
//  cerr << hp << " " << hash << endl;
    if(hash == hp)
        Occ.push_back(0);
    for(int i = m;i < n;i++){
        hash -= (pw[m-1] * S[i-m])%hMod;
        hash += hMod;
        hash %= hMod;
        hash *= Zarib;
        hash += S[i];
        hash %= hMod;
//      cerr << hash << endl;
        if(hash == hp){
            Occ.push_back(i-m+1);
        }
    }
//  for(int i = 0; i < Occ.size();i++){
//      cerr << Occ[i] << endl;
//  }
    if(Occ.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    int fp = 0;
    for(int i = 0; i < n;i++){
        if(fp != Occ.size() && Occ[fp] == i-1)
            fp++;
        ptr[i] = fp;
    }
    for(int i = 0; i < n;i++){
        dp[i] = -1;
    }
    sum[n] = 1;
    for(int i = n-1; i >= 0;i--){
        if(Occ[Occ.size()-1] == i){
            break;
        }
        dp[i] = 1;
        sum[i] = sum[i+1] + 1;
    }
    dp[n] = 1;
    for(int i = Occ[Occ.size()-1]; i >= 0;i--){
        cal(i,n,m);
    }
    cout << (cal(0,n,m)-1 + Mod)%Mod << endl;
    return 0;
}