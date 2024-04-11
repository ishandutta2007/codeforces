#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << N;
    for (int i = 1; i < N; i++)
        cout << " " << i;
    cout << "\n";
    return 0;
}