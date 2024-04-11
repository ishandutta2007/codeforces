#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 300100;

int N;
int arr[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    ll res = 0;
    ll nleft = 0;
    for (int i = 0; i < N; i++)
    {
        while (arr[i] >= 2 && nleft > 0)
        {
            arr[i] -= 2;
            nleft--;
            res++;
        }
        res += arr[i] / 3;
        nleft += arr[i] % 3;
    }
    cout << res << "\n";
}