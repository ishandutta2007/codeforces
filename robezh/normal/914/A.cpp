#include <bits/stdc++.h>
using namespace std;

bool check(int t){
    if(t < 0) return true;
    for(int i = 0; i <= 1000; i++){
        if(i*i == t) return false;
    }
    return true;
}

int main(){
    int res = -1000000000;

    int n;
    int num[1005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    for(int i = 0; i < n; i++){
        if(check(num[i])){
            res = max(res, num[i]);
        }
    }
    cout << res;

}