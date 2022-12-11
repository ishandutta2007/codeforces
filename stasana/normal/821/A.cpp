#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a[50][50];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            if(a[x][y] == 1)
                continue;
            bool f = false;
            for(int s = 0; s < n; ++s){
                for(int t = 0; t < n; ++t){
                    if(a[x][y] == a[x][s] + a[t][y])
                        f = true;
                }
            }
            if(!f){
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}