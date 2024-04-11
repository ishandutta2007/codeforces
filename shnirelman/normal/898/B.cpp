#include <iostream>

using namespace std;

int main(){
    int n, a, b, n1;
    cin >> n >> a >> b;
    //cout << n;

    int x = 0;
    int y = 0;
    n1 = n;
    bool flag = false, flag1 = false;
    while(!flag){

        if(n1 % b == 0 && n1 / b >= 0){
            flag = true;
            flag1 = true;
            y = n1 / b;
        }
        //cout << x << ' ';
        if(n1 < 0)flag = true;
        x++;
        n1 -= a;

    }
    x--;

    if(!flag1)cout << "NO";
    else cout << "YES" << endl << x << ' ' << y << endl;
}