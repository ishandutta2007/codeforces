#include <iostream>
using namespace std;

char f[102][102];
int ans[102][102];

int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int r, c, k;
        cin >> r >> c >> k;
        int n = 0;
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++){
            cin >> f[i][j];
            if(f[i][j] == 'R') n++;
        }
        int m = n % k;
        n /= k;
        int now = 1;
        int l = 0;
        int x = 0, y = 0;
        if(f[x][y] == 'R') l++;
        while(x < r){
            ans[x][y] = now;
            if(x % 2 == 0 && y != c - 1) y++;
            else if(x % 2 == 0 && y == c - 1) x++;
            else if(x % 2 == 1 && y != 0) y--;
            else if(x % 2 == 1 && y == 0) x++;
            if(f[x][y] == 'R'){
                l++;
                if((now <= m && l == n + 2) || (now > m && l == n + 1)){
                    l = 1;
                    now++;
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(ans[i][j] <= 26) cout << (char)('a' + ans[i][j] - 1);
                else if(ans[i][j] <= 52) cout << (char)('A' + (ans[i][j] - 27));
                else cout << (char)('0' + (ans[i][j] - 53));
            }
            cout << endl;
        }
    }
}