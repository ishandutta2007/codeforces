#include <iostream>

using namespace std;

int a[4], b[4];

int main()
{
    for (int i = 0; i < 4; ++i) cin >> a[i] >> b[i];

    if (((a[0] > b[2] && b[1] > a[3]) && (a[0] > b[3] && b[1] > a[2])) || ((a[1] > b[2] && b[0] > a[3]) && (a[1] > b[3] && b[0] > a[2])))
        cout << "Team 1";
    else if (((a[0] < b[2] && b[1] < a[3]) || (a[0] < b[3] && b[1] < a[2])) && ((a[1] < b[2] && b[0] < a[3]) || (a[1] < b[3] && b[0] < a[2])))
        cout << "Team 2";
    else
        cout << "Draw";

    return 0;
}