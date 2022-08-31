#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string sep = "";
    for (int a = 0; a < (n + 1) / 2; a++)
    {
        cout << sep << a + 1;
        sep = " ";
        if (n - a != a + 1)
           cout << sep << n - a;
    }
}