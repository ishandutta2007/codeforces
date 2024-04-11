#include <iostream>

using namespace std;

int main()
{
int m, n;
cin >> m >> n;
if (m == 0) cout << ((n==0)?"0 0\n" : "Impossible\n");
else if (n == 0)
cout << m << " " << m << "\n";
else cout << m + n - min (m, n) << " " << m + n - 1 << "\n";
return 0;
}