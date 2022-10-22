#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 100000000;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[252][252];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int x[252]{0}, y[252]{0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            x[i] = max(x[i], a[i][j]);
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            y[j] = max(y[j], a[i][j]);
        }
    }
    sort(x, x + n);
    sort(y, y + m);
    x[n] = INF;
    y[m] = INF;
    int i = 0, j = 0, k = 1;
    bool b[100000]{0};
    while(i < n && j < m){
        if(x[i] < y[j]){
            for(int l = m - 1; l > j; l--){
                a[i][l] = k;
                b[k] = true;
                while(b[k]){
                    k++;
                }
            }
            b[x[i]] = true;
            a[i][j] = x[i];
            i++;
        }
        else if(x[i] > y[j]){
            for(int l = n - 1; l > i; l--){
                a[l][j] = k;
                b[k] = true;
                while(b[k]){
                    k++;
                }
            }
            b[y[j]] = true;
            a[i][j] = y[j];
            j++;
        }
        else{
            for(int l = m - 1; l > j; l--){
                a[i][l] = k;
                b[k] = true;
                while(b[k]){
                    k++;
                }
            }
            for(int l = n - 1; l > i; l--){
                a[l][j] = k;
                b[k] = true;
                while(b[k]){
                    k++;
                }
            }
            b[x[i]] = true;
            a[i][j] = x[i];
            i++;
            j++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}