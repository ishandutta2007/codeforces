#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int>A;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        A.push_back(x);
    }
    int l = -1;
    int r = m;
    while (l + 1 < r){
        int k = (l + r) / 2;
        int last = m - 1;
        int f = 0;
        for (int i = n - 1; i >= 0; i--){
            int g = A[i] + k;
            if (g >= m){
                if (A[i] > last){
                    last = min(last, g % m);
                }
            }else{
                if (A[i] > last){
                    f = 1;
                }else{
                    last = min(last, A[i] + k);
                }
            }
        }
        if (f == 1){
            l = k;
        }else{
            r = k;
        }
    }
    cout << l + 1;
    return 0;
}