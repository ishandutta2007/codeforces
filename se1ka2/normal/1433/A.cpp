#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        cout << (n[0] - '1') * 10 + (int)n.size() * ((int)n.size() + 1) / 2 << endl;
    }
}