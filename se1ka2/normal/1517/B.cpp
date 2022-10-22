#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int b[102][102];
PP p[10005];
int ans[102][102];
bool d[102][102];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> b[i][j];
                p[i * m + j] = PP(b[i][j], P(i, j));
            }
        }
        sort(p, p + n * m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = -1;
                d[i][j] = false;
            }
        }
        for(int k = 0; k < m; k++){
            int i = p[k].second.first, j = p[k].second.second;
            ans[i][k] = p[k].first;
            d[i][j] = true;
        }
        for(int i = 0; i < n; i++){
            int j = 0, k = 0;
            while(j < m && k < m){
                while(d[i][j] && j < m) j++;
                while(ans[i][k] >= 0 && k < m) k++;
                ans[i][k++] = b[i][j++];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}