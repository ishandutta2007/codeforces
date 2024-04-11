#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int r[4]{0};
    for(int k = 0; k < 4; k++){
        string c[102];
        for(int i = 0; i < n; i++){
            cin >> c[i];
            for(int j = 0; j < n; j++) if((i + j) % 2 == c[i][j] - '0') r[k]++;
        }
    }
    sort(r, r + 4, greater<int>());
    cout << (n * n - r[0]) + (n * n - r[1]) + r[2] + r[3] << endl;
}