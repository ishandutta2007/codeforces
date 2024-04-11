#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
string s; int n;
set<int> f[200][200];
vector<pair<int,int> > ans;
int fen[200009];
int nx[200009],pr[200009],NX[200009],PR[200009];
int Cnt[200009];
void upd(int x, int d){
    while(x <= n){
        fen[x] += d;
        x += (x & -x);
    }
}
int cnt(int x){
    int pas = 0;
    while(x){
        pas += fen[x];
        x -= (x & -x);
    }
    return pas;
}
void ER(int l){
    int r = nx[l];
    //cout<<l<<"-"<<r<<endl;
    int L = cnt(l-1) + 1, R = cnt(r);
    ans.push_back({L,R});
    PR[NX[r]] = PR[l];
    NX[PR[l]] = NX[r];
    while(1){
        upd(l, -1);
        l = NX[l];
        if(l > r) break;
    }
}
void rem(int l){
    int r =nx[l];
    int r1 = PR[l], l1 = pr[r1], l2 = NX[r], r2 = nx[l2];
    //cout<<l1<<"+"<<r1<<" "<<l<<" "<<r<<" "<<l2<<" "<<r2<<endl;
    if(s[l] == s[r]){
        f[s[l]][s[r]].erase(l);
    }
    else{
        if(l1 > 1) f[s[l1]][s[r1]].erase(l1);
        if(r2 < n) f[s[l2]][s[r2]].erase(l2);
        if(l1 > 1 && r2 < n) f[s[l1]][s[r2]].insert(l1);
        f[s[l]][s[r]].erase(l);
        Cnt[s[r]]--;
        Cnt[s[r1]]--;
        pr[r2] = l1;
        nx[l1] = r2;
    }
    ER(l);
}
void solve(){

    ans.clear();
    cin >> s; n =s.size();
    for(int i = 1; i <= n; i++)
        fen[i] = 0;
    for(int i = 1; i <= n; i++)
        upd(i,1);
    s = '#' + s;
    int l = 1;
    vector<pair<int,int> >v;
    for(int i = 2; i <= n; i++){

        if(s[i] == s[i-1]) {v.push_back({l,i-1});
                            nx[l] = i-1;
                            pr[i-1] = l;
                            l = i;
                            }
        else continue;
    }
    v.push_back({l, n});
    nx[l] = n;
    pr[n] = l;
    for(int i = 1; i <= n; i++){
        PR[i] = i-1;
        NX[i] = i+1;

    }
    if(v.size() <= 2){
        for(int i = 0; i < v.size(); i++){
            ER(v[i].first);
        }
    } else{
    for(int i = 0; i < v.size(); i++){
        int l = v[i].first, r = v[i].second;
        if(i < v.size()-1) Cnt[s[r]]++;
        //cout<<l<<" "<<r<<endl;
        if(i && i < v.size()-1) {f[s[l]][s[r]].insert(l);}
    }
    while(1){
        int x = 'a';
        for(int i = 'a'; i <= 'z'; i++){
            if(Cnt[i] > Cnt[x]) x = i;
        }
        //cout<<(char)x<<endl;
        int l = x, r = x;
        for(int i = 'a'; i <= 'z'; i++){
            if(i == x) continue;
            if(f[i][x].size())
            {l = i, r = x; break;}
            if(f[x][i].size()) {l = x, r = i; break;}
        }
        if(l == r) break;
        int i = *(f[l][r].begin());
        rem(i);
    }
    for(int i = 'a'; i <= 'z'; i++)
        for(int j = 'a'; j <= 'z'; j++)
            while(f[i][j].size())
                rem(*f[i][j].begin());
    if(nx[1] == n){
        ER(1);
    }
    else ER(1), ER(pr[n]);
    }
    cout << ans.size()<<endl;
    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    for(int i = 'a'; i <= 'z'; i++)
        Cnt[i] = 0;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}