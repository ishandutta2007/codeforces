#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int L = 50;

int n;
bool good[55][55];

int main(){
    for(int i = 0; i <= L; i++){
        for(int j = 0; j <= L; j++){
            good[i][j] = true;
        }
    }

    for(int i = 0; i <= L; i++){
        for(int j = 0; j <= L; j++){
            for(int pi = 0; pi <= L; pi++){
                for(int pj = 0; pj <= L; pj++){
                    if(4 * pi + 9 * pj < 4 * i + 9 * j && (4 * pi + 9 * pj - 4 * i - 9 * j) % 49 == 0){
                        good[i][j] = false;
                    }
                }
            }
        }
    }

    long long ans = 0;
    cin >> n;
    for(int num4 = 0; num4 <= n && num4 <= L && num4 < 9; num4 ++){
        for(int num9 = 0; num9 + num4 <= n && num9 <= L; num9++){
            if(good[num4][num9]) ans += (n - num4 - num9 + 1);
        }
    }
    cout << ans << endl;

}