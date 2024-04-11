#include <iostream>
using namespace std;

int N, A;
double HX, HY;
double UX, UY;
double LA, LB, LC;

bool lt(double x, double y){
    return LA * x + LB * y + LC < 0;
}

int main(){
    cin >> HX >> HY >> UX >> UY;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> LA >> LB >> LC;
        A += lt(HX, HY) ^ lt(UX, UY);
    }

    cout << A << endl;
    return 0;
}