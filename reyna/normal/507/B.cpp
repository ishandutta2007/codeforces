//In the name of God
#include <iostream>
#include <cmath>
using namespace std;
long double dis(long long x,long long y,long long X,long long Y){
    return sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
}
int main(){
    int r,x,y,X,Y;
    cin >> r >> x >> y >> X >> Y;
    if((long double)fmod(dis(x,y,X,Y)/(2 * r),1) == (long double)0)
        cout << (long long)dis(x,y,X,Y)/(2 * r) << endl;
    else
        cout << (long long)dis(x,y,X,Y)/(2 * r)+1 << endl;
    return 0;
}