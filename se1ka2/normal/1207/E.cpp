#include <iostream>
using namespace std;

int main()
{
    cout << "? ";
    for(int i = 1; i <= 100; i++){
        cout << (i << 7) << " ";
    }
    cout << endl;
    fflush(stdout);
    int l;
    cin >> l;
    l &= ((1 << 7) - 1);
    cout << "? ";
    for(int i = 1; i <= 100; i++){
        cout << i << " ";
    }
    cout << endl;
    fflush(stdout);
    int h;
    cin >> h;
    h &= (((1 << 7) - 1) << 7);
    cout << "! " << h + l;
    fflush(stdout);
}