#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    int g = arr[0];
    for (int i = 1; i < N; i++)
        g = gcd (g, arr[i]);
    
    for (int i = 0; i < N; i++)
        arr[i] /= g;
    
    bool good = true;
    for (int i = 0; i < N; i++)
    {
        while (arr[i] % 2 == 0)
            arr[i] /= 2;
        while (arr[i] % 3 == 0)
            arr[i] /= 3;
        if (arr[i] != 1)
            good = false;
    }
    
    if (good) cout << "Yes\n";
    else cout << "No\n";
    
    //system ("Pause");
    return 0;
}