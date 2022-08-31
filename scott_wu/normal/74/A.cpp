#include <iostream>
#include <string>

using namespace std;

const int INF = 100000000;

string names[60];

int main()
{
    int max = -1 * INF;
    int loc = -1;
    int n;
    cin >> n;
    for (int a = 0; a < n; a++)
    {
        int temp, sum = 0;
        cin >> names[a];
        cin >> temp;
        sum += 100 * temp;
        cin >> temp;
        sum -= 50 * temp;
        for (int b = 0; b < 5; b++)
        {
            cin >> temp;
            sum += temp;
        }
        if (sum > max)
        {
            max = sum;
            loc = a;
        }
    }
    cout << names[loc] << "\n";
    return 0;
}