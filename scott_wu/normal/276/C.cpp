#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 400100;

int N, Q;
int arr[MAXN];
pair <int, int> xval[MAXN];
int cstart[MAXN];

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        xval[2*i] = make_pair (x, 1);
        xval[2*i+1] = make_pair (y + 1, -1);
    }
    
    sort (xval, xval + 2 * Q);
    
    int cur = 0, cloc = 0;
    for (int i = 0; i < N; i++)
    {
        while (cloc < 2 * Q && xval[cloc].first == i)
        {
            cur += xval[cloc].second;
            cloc++;
        }
        
        cstart[i] = cur;
    }
    
    sort (cstart, cstart + N);
    sort (arr, arr + N);
    
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        //cout << cstart[i] << "\n";
        ans += cstart[i] * (ll) arr[i];
    }
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}