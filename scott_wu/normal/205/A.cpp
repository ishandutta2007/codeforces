#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> x[100100];

int main()
{
    int arr[100100];
    int N;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        x[i] = make_pair (arr[i], i);
    }
    
    if (N == 1)
    {
        cout << "1\n";
        return 0;
    }
    
    sort (x, x + N);
    if (x[0].first == x[1].first)
    {
        cout << "Still Rozdil\n";
        return 0;
    }
    else
    {
        cout << x[0].second + 1 << "\n";
        return 0;
    }
}