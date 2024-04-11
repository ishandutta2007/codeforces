#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int now = 1;
    for(int i = 0; i < n / 2; i++){
        cout << now << " " << n * 2 + 1 - now << " ";
        now += 2;
    }
    cout << now << " ";
    now = 2;
    for(int i = 0; i < n / 2; i++){
        cout << now << " " << n * 2 + 1 - now << " ";
        now += 2;
    }
    cout << now << endl;
}