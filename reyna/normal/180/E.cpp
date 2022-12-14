//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 1e5 + 1e3;
vector<int> col[Maxn];
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < n;i++){
        int now;
        cin >> now;
        col[--now].push_back(i);
    }
    int ans = 1;
    for(int i = 0; i < m;i++){
        if(!col[i].size())
            continue;
//      cerr << i << " START !!! " << endl;
        int sp = 0;
        int now = 0;
        for(int j = 0; j < col[i].size();j++){
            if(j)
                now -= col[i][j] - col[i][j-1] - 1;
            while(sp != col[i].size()-1 && now + col[i][sp+1]-col[i][sp]-1 <= k){
                now += col[i][sp+1]-col[i][sp++]-1;
            }
//          cerr << j << " " << sp << " " << now << endl;
            ans = max(ans,sp-j+1);
        }
    }
    cout << ans << endl;
    return 0;
}