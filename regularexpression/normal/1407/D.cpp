#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+17;
mt19937 rnd(51);
int n, h[N],dp[N];
int mn[20][N],mx[20][N],lg[N];
void gen(){
    n = rnd() % 10 + 1;
    for (int i = 0; i < n; i++) h[i] = rnd() % 20 + 1;
}
int get_mn(int l, int r) {
    int kek = lg[r-l];
    return min(mn[kek][l], mn[kek][r-(1<<kek)]);
}
int get_mx(int l, int r){
    int kek = lg[r-l];
    return max(mx[kek][l], mx[kek][r-(1<<kek)]);
}

int solve() {
    for(int i = 0; i <n; i++){
        mn[0][i]=mx[0][i]=h[i];
    }
    for(int i=2; i<N;i++)lg[i]=lg[i/2] + 1;
    for(int pw=1;pw<20; pw++){
        for(int i = 0; i +(1<<pw)<= n; i++){
            mn[pw][i] = min(mn[pw-1][i],mn[pw-1][i+(1<<(pw-1))]);
            mx[pw][i] = max(mx[pw-1][i],mx[pw-1][i+(1<<(pw-1))]);
        }
    }
    for (int i = 0; i < n; i++) dp[i] = 1e9;
    dp[0] = 0;
    vector< pair< int, int> > ed;
    vector< int > s1, s2;
    for (int i = 0; i < n; i++) {
        while (!s1.empty() &&h[s1.back()]<=h[i]) {ed.push_back({s1.back(), i}); s1.pop_back();}
        while(!s2.empty()&&h[s2.back()] >= h[i]) {ed.push_back({s2.back(), i}); s2.pop_back();}
        s1.push_back(i);s2.push_back(i);
    }
    s1=s2={};
    for(int i=n-1; i>=0;i--){
        while(!s1.empty() && h[s1.back()] <= h[i]) {ed.push_back({i, s1.back()}); s1.pop_back();}
        while (!s2.empty()&& h[s2.back()] >= h[i]) {ed.push_back({i, s2.back()});s2.pop_back();}
        s1.push_back(i);
        s2.push_back(i);
    }
    sort(ed.begin(),ed.end());
    for (auto edd : ed) {
        bool f = edd.first+1 == edd.second || get_mn(edd.first + 1, edd.second) > max(h[edd.first],h[edd.second]);
        bool ff = edd.first + 1==edd.second || get_mx(edd.first + 1, edd.second) < min(h[edd.first],h[edd.second]);
        if(f||ff) dp[edd.second]= min(dp[edd.second], dp[edd.first] + 1);
    }
    return dp[n - 1];
}
int solve1() {
    for (int i = 0; i < n; i++) dp[i] = 1e9;
    dp[0] = 0;
    vector< pair< int, int> > ed;
    for (int i=0; i<n; i++)for(int j=i+1;j<n;j++) ed.push_back({i,j});
    sort(ed.begin(),ed.end());
    for (auto edd : ed) {
        bool f = 1, ff = 1;
        for (int i = edd.first + 1; i < edd.second; i++){
            f &= h[i] < h[edd.first] && h[i] < h[edd.second];
            ff &= h[i] > h[edd.first] && h[i] > h[edd.second];
        }
        if (f || ff)dp[edd.second] = min(dp[edd.second],dp[edd.first] + 1);
    }
    return dp[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);/*
    while (1){
        gen();
        if(solve()!=solve1()){
            cout<<n<<endl;
            for (int i = 0; i < n; i++) cout << h[i]<< " ";
            cout << endl;
            return 0;
        }//else cout<<"good"<<endl;
    }*/
    cin>>n;
    for (int i = 0; i < n; i++)cin>>h[i];
    cout << solve();
    return 0;
}