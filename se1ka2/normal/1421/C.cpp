#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    cout << 3 << endl;
    cout << "R 2" << endl;
    cout << "L " << n << endl;
    cout << "L " << n - 1 << endl;
}