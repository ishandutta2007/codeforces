//In the name of God
#include <iostream>
using namespace std;
int main(){
    int a,b,t1,t2;
    cin >> a >> b >> t1 >> t2;
    double p1,p2;
    p1 = max(((double)a * 3)/10,a - ((double)t1 * a)/250);
    p2 = max(((double)b * 3)/10,b - ((double)t2 * b)/250);
    if(p1 > p2)
        cout << "Misha" << endl;
    else if(p1 < p2)
        cout << "Vasya" << endl;
    else
        cout << "Tie" << endl;
    return 0;
}