#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        double d;
        cin >> d;
        if(0 < d && d < 4) cout << "N" << endl;
        else{
            double r = sqrt(d * d - d * 4);
            cout << "Y" << " ";
            cout << fixed << setprecision(15) << (d + r) / 2 << " " << (d - r) / 2 << endl;
        }
    }
}