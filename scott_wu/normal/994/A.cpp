#include <iostream>

using namespace std;

int arr[10];
bool b[10];

int main()
{
    int N, M;
    for (int i = 0; i < 10; i++)
        b[i] = false;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < M; i++)
    {
        int x; cin >> x;
        b[x] = true;
    }
    
    for (int i = 0; i < N; i++)
        if (b[arr[i]]) cout << arr[i] << " ";
}