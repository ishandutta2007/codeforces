#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    char snake[50][50];
    cin >> n >> m;
    memset(snake, '.', sizeof(snake));
    
    for (int i=0; i<n; i++) {
        if (i % 2 == 0)
            for (int j=0; j<m; j++)
                snake[i][j] = '#';
        else {
            if ((i-1)/2 % 2 == 0)
                snake[i][m-1] = '#';
            else
                snake[i][0] = '#';
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cout << snake[i][j];
        cout << endl;
    }
    
    return 0;
}