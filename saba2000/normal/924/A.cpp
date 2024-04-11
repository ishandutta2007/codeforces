#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt=0;
vector<int> v[100009];
int F[109][2009];
int f[100009];
int c[100009];

void dfs(int x){
    f[x] =  1;
    c[x] =  cnt;
    for (int i = 0; i < v[x].size(); i++)
        if(!f[v[x][i]]) dfs(v[x][i]);
}
char a[1009][1009];
main(){
    int n,m;
    cin >> n >> m;
    for (int i =0 ; i < n; i++){
            for (int j =0; j < m; j++){
                cin >>a[i][j];
                if(a[i][j] == '#') {v[i].push_back(j+1000);
                F[i][j+1000]= 1;
                v[j+1000].push_back(i);}
            }}
    for (int i = 0; i < n; i++){
        if(f[i]==0) {dfs(i);
        cnt ++;}
    }
    for (int j = 0; j < m; j++)
        if(f[j+1000]==0) {dfs(j+1000);cnt++;}
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        if(c[i] == c[j+1000] && F[i][j+1000]==0) {
              //  cout <<i <<" "<<j << endl;
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl;
    return 0;
}