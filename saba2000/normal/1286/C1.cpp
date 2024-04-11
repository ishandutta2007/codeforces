#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a[509];
int f[509],g[509];
char ans[509];
int F[509];
vector<pair<int,string> > e[509];
void ask(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    vector<string> v[109];
    for(int i = 'a'; i <= 'z'; i++)
        f[i] = 0,g[i] = 0;
    int n = r-l+1;
    for(int i =0; i <= n; i++)
        a[i]  ="";
    for(int i = 0; i < n*(n+1)/2; i++){
        string x;
        cin >> x;
        v[(int)x.size()].push_back(x);
    }
    for(string u : v[1])
        g[u[0]]++;
    for(int i = 1; i <= n-i+1; i++){
        for(int j = 'a'; j <= 'z'; j++)
            f[j] = g[j] * (i + 1);
        for(int j = 1; j < i; j++)
            f[a[j][0]] += (j - (i+1)),
            f[a[j][1]] += (j - (i+1));
        for(string u : v[i+1]){
            for(char c : u)
                f[c]--;
        }
        for(int j ='a'; j <='z'; j++)
            while(f[j]) f[j]--,a[i]+=j;
        e[l+i-1].push_back({r-i+1, a[i]});
        e[r-i+1].push_back({l+i-1, a[i]});
    }


}
char sub(string s, char t){
    return t == s[0] ? s[1] : s[0];
}
char h(string a, string b, string c){
    F[a[0]]++; F[a[1]]++;
    F[b[0]]++; F[b[1]]++;
    F[c[0]]--; F[c[1]]--;
    for(int i = 'a'; i <= 'z'; i++)
        if(F[i]) return i;
}
void dfs(int x){
    for(auto y : e[x]){
        if(ans[y.first]) continue;
        ans[y.first] = sub(y.second, ans[x]);
        dfs(y.first);
    }
}
main(){
    int n;
    cin >> n;
    ask(1,n);
    if(n % 2 == 1) ans[(n+1)/2] = e[(n+1)/2][0].second[0];
    if(n >1){
        ask(1,n/2);
        ask(1,n/2+1);

        if(n % 2 == 1){
            ans[1] = sub(e[1][2].second,ans[n/2+1]);
        }
        else if(n == 2) ans[1] =  e[1][1].second[0]; else
            ans[1] = h(e[1][1].second,e[1][2].second, e[n/2][0].second);
        dfs(1);
    }
    cout<<"! ";
    for(int i = 1; i <= n; i++){
        cout<<ans[i];
    }
    cout<<endl;
}