#include <bits/stdc++.h>
#include <Math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    bool flag = false;
    for(int i = 2; i <= sqrt(n); i++)if(n % i == 0)
        flag = true;
    if(!flag){
        cout << 1;
        return 0;
    }

    if(n % 2 == 0)cout << 2;
    else {
        n -= 2;
        flag = false;
        for(int i = 2; i <= sqrt(n); i++)if(n % i == 0)
            flag = true;
        if(!flag){
            cout << 2;
        }
        else cout << 3;
    }
}