#include<iostream>
#include <cmath>
using namespace std;

int A, B;

bool is_square(int x){
    int root = floor(sqrt(x));
    return root * root == x;
}

int main(){
    cin >> A >> B;

    for(int h=1; h<A; h++){
        int hor = A * A - h * h;
        if(!is_square(hor)) continue;

        double bx = -h, by = sqrt(hor);
        double sc = B / sqrt(bx * bx + by * by);

        int BX = round(bx * sc);
        if(abs(BX - bx * sc) > 1e-9) continue;
        int BY = round(by * sc);
        if(abs(BY - by * sc) > 1e-9) continue;

        if(BY == h) continue;

        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << floor(sqrt(hor)) << " " << h << endl;
        cout << round(bx * sc) << " " << round(by * sc) << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}