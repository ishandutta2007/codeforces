//In the name of God
#include <iostream>
using namespace std;
int ans;
const int Maxn = 1e3+20;
string mat[Maxn];
bool cmp[Maxn];
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        cin >> mat[i];
    }
    for(int j = 0; j < m;j++){
        bool flag = 0;
        for(int i = 1; i < n;i++){
            if(!cmp[i-1] && mat[i][j] < mat[i-1][j]){
                ans++;
                flag = 1;
                break;
            }
        }
        if(flag)
            continue;
        for(int i = 1; i < n;i++){
            if(mat[i][j] != mat[i-1][j])
                cmp[i-1] = true;
        }
    }
    cout << ans << endl;
    return 0;
}