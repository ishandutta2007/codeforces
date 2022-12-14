//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 530;
int W[Maxn];
bool vis[Maxn];
int order[Maxn * 2];
long long ans = 0;
int pos[Maxn];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        cin >> W[i];
    int cnt = 0;
    for(int i = 0; i < n;i++)
        pos[i] = Maxn * Maxn;
    for(int i = 0; i < m;i++){
        cin >> order[i];
        if(!vis[--order[i]]){
            pos[order[i]] = cnt++;
        }
        vis[order[i]] = 1;
    }
    for(int i = 0; i < m;i++){
        int now = pos[order[i]];
//      cerr << order[i] << " start " << endl;
        for(int j = 0; j < n;j++){
//          cerr << j << " " << pos[j] << endl;
            if(pos[j] < now){
                ans += W[j];
                pos[j]++;
            }
        }
        pos[order[i]] = 0;
    }
    cout << ans << endl;
    return 0;
}