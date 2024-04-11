#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
double R, x11, x22, y11, y22;
double R2, x3, y3;
int main()
{
    cin>>R>>x11>>y11>>x22>>y22;
    R2 = (R+sqrt((x11-x22)*(x11-x22)+(y11-y22)*(y11-y22)))/2;
    if(R2>=R)
    {
        cout<<fixed<<setprecision(8)<<x11<<" "<<y11<<" "<<R<<endl;
        return 0;
    }
    if(x11==x22&&y11==y22)
    {
        cout<<fixed<<setprecision(8)<<x11+R/2<<" "<<y11<<" "<<R/2<<endl;
        return 0;
    }
    x3 = x22+R2*(x11-x22)/sqrt((x11-x22)*(x11-x22)+(y11-y22)*(y11-y22));
    y3 = y22+R2*(y11-y22)/sqrt((x11-x22)*(x11-x22)+(y11-y22)*(y11-y22));
    cout<<fixed<<setprecision(8)<<x3<<" "<<y3<<" "<<R2<<endl;
}