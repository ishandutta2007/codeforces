#include <iostream>

using namespace std;

int N;
int arr[1000100];

int main()
{
    cin >> N;
    
    int s, t;
    cin >> s >> t;
    s--, t--;
    
    for (int i = 0; i < N; i++)
    {    cin >> arr[i];
        arr[i]--;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (s == t)
        {
            cout << i << "\n";
            return 0;
        }
        s = arr[s];
    }
    
    cout << "-1\n";
    return 0;
}