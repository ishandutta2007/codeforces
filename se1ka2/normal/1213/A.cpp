#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10002];
    int ans[2] {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans[a[i] % 2]++;
    }
    cout << n - max(ans[0], ans[1]) << endl;
}