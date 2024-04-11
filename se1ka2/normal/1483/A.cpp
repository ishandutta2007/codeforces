#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) v[i].clear();
        int d[100005];
        for(int i = 0; i <= n; i++) d[i] = 0;
        for(int i = 0; i < m; i++){
            int k;
            cin >> k;
            v[i].resize(k);
            for(int j = 0; j < k; j++){
                cin >> v[i][j];
                d[v[i][j]]++;
            }
        }
        int u = -1;
        for(int i = 0; i <= n; i++){
            if(d[i] >= (m + 1) / 2){
                u = i;
                break;
            }
        }
        if(u == -1){
            cout << "YES" << endl;
            for(int i = 0; i < m; i++) cout << v[i][0] << " ";
            cout << endl;
        }
        else{
            int c = 0;
            for(int i = 0; i < m; i++){
                if((int)v[i].size() == 1 && v[i][0] == u) c++;
            }
            if(c > (m + 1) / 2){
                cout << "NO" << endl;
            }
            else{
                c = (m + 1) / 2 - c;
                cout << "YES" << endl;
                for(int i = 0; i < m; i++){
                    if((int)v[i].size() == 1 && v[i][0] == u) cout << u << " ";
                    else if(c){
                        bool f = false;
                        for(int k : v[i]){
                            if(k == u){
                                cout << k << " ";
                                c--;
                                f = true;
                                break;
                            }
                        }
                        if(!f) cout << v[i][0] << " ";
                    }
                    else if(v[i][0] != u) cout << v[i][0] << " ";
                    else cout << v[i][1] << " ";
                }
                cout << endl;
            }
        }
    }
}