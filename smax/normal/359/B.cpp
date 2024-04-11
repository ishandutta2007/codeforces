#include <iostream>

using namespace std;

int arr[100001];

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < 2*n; ++i)
        arr[i] = i+1;

    while (k--) {
        swap(arr[2*k], arr[2*k+1]);
    }

    for (int i = 0; i < 2*n; ++i)
        cout << arr[i] << ((i == 2*n-1) ? "\n" : " ");
    return 0;
}