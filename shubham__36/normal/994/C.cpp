#include <iostream>

using namespace std;

int main()
{
    int a[8],b[8];
    for(int i=0;i<8;i++){
        cin >> a[i];
        cin >> b[i];
    }
    int x1=0,y1=0,x2=0,y2=0;
    for(int i=0;i<4;i++){
        x1+=a[i];
        y1+=b[i];
    }
    for(int i=4;i<8;i++){
        x2+=a[i];
        y2+=b[i];
    }
    int side1=abs(a[0]-a[1])+abs(b[0]-b[1]);
    int side2=(abs(a[4]-a[5]));
    if(abs(x1-x2)/4.0 <= side1/2.0+side2 && abs(y1-y2)/4.0 <= side1/2.0) cout << "YES" << endl;
    else if(abs(y1-y2)/4.0 <= side1/2.0+side2 && abs(x1-x2)/4.0 <= side1/2.0) cout << "YES" << endl;
    else if(abs(y1-y2)/4.0 + abs(x1-x2)/4.0 <= (side1+side2) && abs(x1-x2)/4.0 > side1/2.0 && abs(y1-y2)/4.0 > side1/2.0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}