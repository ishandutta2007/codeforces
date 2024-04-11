#include <iostream>

using namespace std;

int main()
{
    int N, X1, X2, Y1, Y2;
    
    cin >> N >> X1 >> Y1 >> X2 >> Y2;
    
    int xd = X2 - X1, yd = Y2 - Y1;
    
    for (int i = 0; i < N; i++)
    {
        char ch; cin >> ch;
        
        if (ch == 'N')
        {
            if (yd > 0) yd--;
        }
        else if (ch == 'S') {if (yd < 0) yd++;}
        else if (ch == 'E') {if (xd > 0) xd--;}
        else if (ch == 'W') {if (xd < 0) xd++;}
        
        //cout << ch << "\n";
        //cout << xd << " " << yd << "\n";
        if (xd == 0 && yd == 0)
        {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    //system ("Pause");
    return 0;
}