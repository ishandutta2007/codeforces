#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[500009],s[500009];
ll mod = 1e9 + 7;
int P(int a){
    if(p[a] == a) return a;
    p[a] = P(p[a]);
    return p[a];
}
void un(int a, int b){
    a = P(a); b = P(b);
    if(s[a] > s[b]) swap(a,b);
    p[a] = b;
    s[b] += s[a];

}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= m; i++){
        p[i] = i;
        s[i] = 1;
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        int a, b;
        if(k == 1){
            a = 0;
            cin >> b;
        }
        else cin >> a >> b;
        if(P(a) == P(b))
            continue;
        else{
            un(a,b);
            ans.push_back(i);
        }
    }
    ll Ans = 1;
    for(int i = 0; i < ans.size(); i++){
        Ans = Ans * 2 % mod;
    }
    cout<<Ans<<" "<<ans.size()<<endl;
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;


}