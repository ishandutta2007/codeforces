#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n < 7){
        cout << m << endl;
        return 0;
    }
    int a[50], b[50];
    vector<int> v[7];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        int d[7][7];
        for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) d[j][k] = 0;
        for(int j = 0; j < m; j++){
            if(a[j] != i && b[j] != i){
                d[a[j]][b[j]] = 1;
                d[b[j]][a[j]] = 1;
                sum++;
            }
        }
        for(int j = 0; j < n; j++){
            int nsum = sum;
            if(j == i) continue;
            for(int k = 0; k < m; k++){
                if(a[k] == i && d[j][b[k]] == 0){
                    nsum++;
                }
                if(b[k] == i && d[a[k]][j] == 0){
                    nsum++;
                }
            }
            ans = max(ans, nsum);
        }
    }
    cout << ans << endl;
}