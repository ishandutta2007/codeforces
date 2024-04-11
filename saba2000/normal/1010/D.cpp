#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000009];
char S[1000009];
int f[1000009];
int G[1000009];
int ans[1000009];
void dfs(int x){
    if(S[x] == 'I'){
        return;
    }
    for(int i = 0; i < v[x].size(); i++)
        dfs(v[x][i]);
    if(S[x] == 'N'){
        f[x] = 1 - f[v[x][0]];
    }
    if(S[x] == 'X'){
        f[x] = (f[v[x][0]]^f[v[x][1]]);
    }
    if(S[x] == 'A'){
        f[x] = (f[v[x][0]]&f[v[x][1]]);
    }
    if(S[x] == 'O'){
        f[x] = (f[v[x][0]]|f[v[x][1]]);
    }
}
void dfs1(int x){
    if(S[x] == 'I')
        ans[x] = 1;
    if(S[x] == 'N'){
        dfs1(v[x][0]);
    }
    if(S[x] == 'X'){
        dfs1(v[x][0]);
        dfs1(v[x][1]);
    }
    if(S[x] == 'A'){
        int a = f[v[x][0]], b = f[v[x][1]];
        if(b) dfs1(v[x][0]);
        if(a) dfs1(v[x][1]);
    }
    if(S[x] == 'O'){
        int a = f[v[x][0]], b = f[v[x][1]];
        if(!b) dfs1(v[x][0]);
        if(!a) dfs1(v[x][1]);

    }
}
main(){
   int n;
   cin>>n;
   for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        S[i] = s[0];
        if(s == "IN") {
            int a;
           scanf("%d",&a);
            f[i] = a;
            continue;
        }
        int c = 2;
        if(s == "NOT") c = 1;
        while(c--){
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
        }
   }
   dfs(1);
   dfs1(1);
   string ANS= "";
   for(int i = 1; i <= n; i++)
    if(ans[i] && S[i] == 'I') ANS += (char)(1 -f[1]+ '0');
     else if(S[i] == 'I')ANS += (char)(f[1] + '0');
   cout<<ANS<<endl;

}