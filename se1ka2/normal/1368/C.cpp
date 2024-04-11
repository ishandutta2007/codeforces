#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool ans[5][20000];
    for(int i = 0; i < n * 10; i++){
        for(int j = 0; j < 5; j++) ans[j][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        for(int dx = -1; dx <= 1; dx++){
            for(int dy = -1; dy <= 1; dy++){
                ans[(i % 2) * 2 + 1 + dx][i * 2 + 1 + dy] = true;
                ans[(i % 2) * 2 + 1][i * 2 + 1] = false;
            }
        }
    }
    cout << 7 * n + 8 << endl;
    for(int i = 0; i < n * 10; i++){
        for(int j = 0; j < 5; j++) if(ans[j][i]) cout << j << " " << i << endl;
    }
}