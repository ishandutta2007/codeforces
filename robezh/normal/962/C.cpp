#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int comp(int lar, int sma){
    int count = 0;
    while(true){
        while(lar%10 != sma%10){
            lar/=10;
            if(lar == 0) return INF;
            count ++;
        }
        lar /= 10; sma /= 10;
        if(sma == 0){
            while(lar > 0){
                lar /= 10;
                count++;
            }
            break;
        }
    }
    return count;

}

int main() {
    int n;
    //cout << comp(781,87);
    cin >> n;
    int res = INF;
    for(int i = 1; i <= 45000; i++){
        res = min(res, comp(n, i*i));
    }
    cout << (res == INF ? -1 : res);
    return 0;
}