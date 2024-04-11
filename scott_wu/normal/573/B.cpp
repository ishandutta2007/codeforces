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

int N;
int arr[MAXN];
int lval[MAXN], hval[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    lval[0] = 1;
    for (int i = 1; i < N; i++)
        lval[i] = min (arr[i], lval[i-1] + 1);
    hval[N-1] = 1;
    for (int i = N - 2; i >= 0; i--)
        hval[i] = min (arr[i], hval[i+1] + 1);
    
    int res = 0;
    for (int i = 0; i < N; i++)
        res = max (res, min (lval[i], hval[i]));
    cout << res << "\n";
        
    //system ("Pause");
    return 0;
}