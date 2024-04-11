#include <iostream>

using namespace std;

int* b_sort(int* arr, int arrSize) {
    for (int i = arrSize - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    return arr;
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int arr[1000] = {0};
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        b_sort(arr, n);

        int j;
        for (j = 1000; j > 0; j--) {
            if (j <= n && arr[n - j] >= j) {
                break;
            }
        }

        cout << j << endl;
    }
    return 0;
}