#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int p[502];
    for(int i = 0; i < n; i++) cin >> p[i];
    int ans[502][502];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) ans[i][j] = -1;
    }
    for(int i = 0; i < n; i++){
        int x = i, y = i;
        for(int c = 0; c < p[i]; c++){
            ans[x][y] = p[i];
            if(y == 0 || ans[x][y - 1] != -1) x++;
            else y--;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}