#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    while(t--)
        solve();
    return 0;
}
char c[101010];
int id[101010];

int he[101010];
int nothe[101010];
int pluss = 0;
int minuss = 0;
set<int> ok;
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>c[i]>>id[i];
        if(c[i]=='+'){
            he[id[i]]++;
            ++pluss;
        }
        else{
            nothe[id[i]]++;
            ++minuss;
        }
    }
    
    for(int i=1;i<=n;++i){
        cout<<c;
        if(he[i]+(minuss-nothe[i]) == m)
            ok.insert(i);
    }
    
    for(int i=1;i<=n;++i){
        if(c[i]=='+'){
            if(ok.size()==1 && (*ok.begin()==id[i])){
                printf("Truth\n");
            }
            else if(ok.find(id[i])==ok.end()){
                printf("Lie\n");
            }
            else
                printf("Not defined\n");
        }
        else{
            if(ok.size()==1 && (*ok.begin()==id[i])){
                printf("Lie\n");
            }
            else if(ok.find(id[i])==ok.end()){
                printf("Truth\n");
            }
            else
                printf("Not defined\n");
        }
    }
}