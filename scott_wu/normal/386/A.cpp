#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1100];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    int loc = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] > arr[loc])
            loc = i;
    
    sort (arr, arr + N);
    cout << loc + 1 << " " << arr[N-2] << "\n";
    return 0;
}