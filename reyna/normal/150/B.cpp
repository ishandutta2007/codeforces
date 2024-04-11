#include <iostream>
#include <vector>
using namespace std;
vector<int> al[2345];
bool V[2345];
int n,m,k;
int md = 1000*1000*1000+7;
void dfs(int i){
    if(V[i])
        return;
    V[i] = true;
    for(int j = 0; j < al[i].size();j++){
        int next = al[i][j];
        dfs(al[i][j]);
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i <= n-k;i++){
        for(int j = 0; j < k; j++){
            al[j+i].push_back(i+k-j-1);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n;i++){
        if(!V[i]){
            dfs(i);
            cnt++;
        }
    }
    long long a = 1;
    for(int i = 0; i < cnt;i++){
        a*=m;
        a%=md;
    }
    cout << a << endl;
    return 0;
}