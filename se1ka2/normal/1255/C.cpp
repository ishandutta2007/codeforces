#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[100002][3];
    int a[100002][3];
    int b[100002] {0};
    for(int i = 0; i < n - 2; i++) for(int j = 0; j < 3; j++){
        cin >> p[i][j];
        a[p[i][j]][b[p[i][j]]] = i;
        b[p[i][j]]++;
    }
    bool used[100002] {0};
    int next, nnext;
    int i = 1;
    for(; i <= n; i++) if(b[i] == 1) break;
    i = a[i][0];
    for(int j = 0; j < 3; j++) if(b[p[i][j]] == 1) cout << p[i][j] << " ";
    for(int j = 0; j < 3; j++) if(b[p[i][j]] == 2){
        cout << p[i][j] << " ";
        next = p[i][j];
    }
    for(int j = 0; j < 3; j++) if(b[p[i][j]] == 3){
        cout << p[i][j] << " ";
        nnext = p[i][j];
    }
    used[i] = true;
    for(int j = 0; j < 2; j++){
        if(!used[a[next][j]]){
            i = a[next][j];
        }
    }
    for(int j = 0; j < 3; j++){
        if(p[i][j] != next && p[i][j] != nnext){
            next = nnext, nnext = p[i][j];
            cout << nnext << " ";
            break;
        }
    }
    used[i] = true;
    for(int k = 2; k < n - 2; k++){
        for(int j = 0; j < 3; j++){
            if(!used[a[next][j]]){
                i = a[next][j];
            }
        }
        for(int j = 0; j < 3; j++){
            if(p[i][j] != next && p[i][j] != nnext){
                next = nnext, nnext = p[i][j];
                cout << nnext << " ";
                break;
            }
        }
        used[i] = true;
    }
}