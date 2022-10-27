#include <iostream>
#include <cmath>
using namespace std;
const int N=102;
const double PI = acos(-1);

int n,r;
int main(){
    cin>>n>>r;
    double a=2*PI/n; a/=2;
    // sin a = r / (r + R)
    double R = r / (1/sin(a) - 1);
    printf("%.8f\n", R);

}