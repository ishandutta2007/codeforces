#include <iostream>
#include <string>
using namespace std;

int d[10][10][10];

int main()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++) d[i][j][k] = 1000;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    if(k + l == 0) continue;
                    d[i][j][(i * k + j * l) % 10] = min(d[i][j][(i * k + j * l) % 10], k + l - 1);
                }
            }
        }
    }
    string s;
    cin >> s;
    int n = s.size();
    int ans[10][10];
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++){
        ans[i][j] = 0;
        for(int k = 0; k < n - 1; k++){
            if(d[i][j][(10 + (s[k + 1] - s[k])) % 10] == 1000){
                ans[i][j] = -1;
                break;
            }
            ans[i][j] += d[i][j][(10 + (s[k + 1] - s[k])) % 10];
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}