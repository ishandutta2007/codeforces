#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 1){
        cout << "1 " << endl << "1  1";
        return 0;
    }


    cout << max((n) / 2 + 1, 2) << endl;

    int x = 1, y = 1;
    for(int i = 1; i <= n; i++){
        cout << x << ' ' << y << endl;
        if(x >= y)y++;
        else x++;
    }

}