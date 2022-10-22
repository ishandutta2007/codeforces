#include <iostream>
#include <vector>
using namespace std;

int a[300004], b[300004];
vector<int> v[300004];
bool used[300004];
int ans[300004];

int main()
{
    int n, m;
    cin >> n >> m;
    fill(used, used + n, false);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = true;
        ans[i] = num;
        num++;
        if(num >= 4){
            cout << -1 << endl;
            return 0;
        }
        int d[300004] {0};
        for(int x : v[i]) d[x] = 1;
        for(int j = 0; j < n; j++) if(d[j] == 0){
            used[j] = true;
            ans[j] = num;
            if(v[j].size() != v[i].size()){
                cout << -1 << endl;
                return 0;
            }
            for(int x : v[j]) if(d[x] == 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if(num < 3) cout << -1 << endl;
    else for(int i = 0; i < n; i++) printf("%d ", ans[i]);
}