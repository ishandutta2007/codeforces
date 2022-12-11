#include <iostream>

using namespace std;

int main()
{
    long int n, k, max=0, min=0, t, p,a[101],b[101] ;

    cin >> n >> k;
for (long int i = 1; i <= n; i++)
{
    cin >> a[i] >> b[i];
    min = min + a[i];
    max = max + b[i];
//    cout << max << " " << min << endl;
}

if ((k <= max) && (k >= min))
{
    cout << "YES" << endl;
    k = k - min;
    for (long int i = 1; i <= n; i++)
    {
        if (k >= b[i] - a[i]) {cout << b[i] << " "; k = k - b[i] + a[i];} else
        if (k > 0) {cout << a[i] + k << " "; k = 0;} else
        cout << a[i] << " ";
    }
}
else cout << "NO";

}