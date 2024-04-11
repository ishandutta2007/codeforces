#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0, c = 1;
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]) c++;
        if(a[i] < a[i + 1]){
            if(a[i + 1] <= a[i] + k) ans += c;
            c = 1;
        }
    }
    cout << n - ans << endl;
}