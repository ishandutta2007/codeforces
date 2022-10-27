#include <iostream>
using namespace std;

int r1, r2, c1, c2, d1, d2;
bool chk(int x1, int x2, int x3, int x4)
{
    int ok = 1;
    if(x1 == x2 || x1 == x3 || x1 == x4 || x2 == x3 || x2==x4 || x3==x4) ok = 0;
    if(x1 + x2 != r1) ok = 0;
    if(x3 + x4 != r2) ok = 0;
    if(x1 + x3 != c1) ok = 0;
    if(x2 + x4 != c2) ok = 0;
    if(x1 + x4 != d1) ok = 0;
    if(x2 + x3 != d2) ok = 0;
    return ok;
}

int main()
{
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for(int x1=1;x1<=9;x1++)for(int x2=1;x2<=9;x2++)
        for(int x3=1;x3<=9;x3++)for(int x4=1;x4<=9;x4++) {
            if(chk(x1, x2, x3, x4)) {
                cout << x1 << " " << x2 << endl;
                cout << x3 << " " << x4 << endl;
                return 0;
            }
        }
    cout << -1 << endl;
}