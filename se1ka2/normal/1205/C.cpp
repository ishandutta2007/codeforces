#include <iostream>
using namespace std;

bool a[52][52];

void out(int x1, int y1, int x2, int y2){
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
}

void set0(int x1, int y1, int x2, int y2){
    out(x1, y1, x2, y2);
    cin >> a[x2][y2];
    a[x2][y2] = !a[x2][y2];
    a[x2][y2] ^= a[x1][y1];
}

void set1(int x1, int y1, int x2, int y2){
    out(x1, y1, x2, y2);
    cin >> a[x1][y1];
    a[x1][y1] = !a[x1][y1];
    a[x1][y1] ^= a[x2][y2];
}

bool find(int x1, int y1, int x2, int y2, int n){
    bool f = false;
    bool x;
    if(x1 == x2){
        if((a[x1][y1] ^ a[x1][y1 + 2]) == (a[x2][y2 - 2] ^ a[x2][y2])){
            out(x1, y1, x2, y2);
            cin >> x;
            f = true;
        }
    }
    if(x2 - x1 == 1){
        if((a[x1][y1] ^ a[x1][y2]) == (a[x1][y1 + 1] ^ a[x2][y2]) ||
           (a[x1][y1 + 1] ^ a[x2][y2]) == (a[x1][y1] ^ a[x2][y1 + 1]) || 
           (a[x1][y1] ^ a[x2][y1 + 1]) == (a[x2][y1] ^ a[x2][y2])){
            out(x1, y1, x2, y2);
            cin >> x;
            f = true;
        }
    }
    if(x2 - x1 == 2){
        if((a[x1][y1] ^ a[x2][y1]) == (a[x1 + 1][y1] ^ a[x2][y2]) ||
           (a[x1 + 1][y1] ^ a[x2][y2]) == (a[x1][y1] ^ a[x1 + 1][y2]) ||
           (a[x1][y1] ^ a[x1 + 1][y2]) == (a[x1][y2] ^ a[x2][y2])){
            out(x1, y1, x2, y2);
            cin >> x;
            f = true;
        }
    }
    if(x2 - x1 == 3){
        if((a[x1][y1] ^ a[x1 + 2][y1]) == (a[x2][y2] ^ a[x2 - 2][y2])){
            out(x1, y1, x2, y2);
            cin >> x;
            f = true;
        }
    }
    if(f){
        if(x ^ (a[x1][y1] == a[x2][y2])){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if((i + j) % 2) a[i][j] = !a[i][j];
                }
            }
        }
    }
    return f;
}

int main()
{
    int n;
    cin >> n;
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    for(int i = 1; i < n; i++){
        if(i % 2) set0(i - 1, 0, i, 1);
        else set0(i - 2, 0, i, 0);
    }
    a[0][1] = 1;
    set0(0, 1, 2, 1);
    set1(1, 0, 2, 1);
    for(int i = 3; i < n; i++){
        if(i % 2) set0(i - 2, 0, i, 0);
        else set0(i - 1, 0, i, 1);
    }
    for(int i = 0; i < n; i++){
        for(int j = 2; j < n; j++){
            if(i == n && j == n) continue;
            set0(i, j - 2, i, j);
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int k = 0; k < 4; k++){
                if(x + k < n && y + (3 - k) < n){
                    if(find(x, y, x + k, y + (3 - k), n)){
                        cout << "!" << endl;
                        for(int i = 0; i < n; i++){
                            for(int j = 0; j < n; j++) cout << a[i][j];
                            cout << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
}