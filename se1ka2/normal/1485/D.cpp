#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int p[20];
    for(int i = 1; i <= 16; i++) p[i] = i * i * i * i;
    int a[502][502];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int b[502][502];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) b[i][j] = 720720;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i + j) % 2) b[i][j] += p[a[i][j]];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << b[i][j] << " ";
        cout << endl;
    }
}