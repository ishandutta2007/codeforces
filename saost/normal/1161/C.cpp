#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100];
int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    int i=1; while (a[i] == a[i+1]) ++i;
    if (i<=n/2) cout << "Alice"; else cout << "Bob";
}