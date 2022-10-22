#include <iostream>

using namespace std;

int main()
{
    int n, B, a[100], b[99], q=0, k=0;
    cin >> n >> B;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n-1; i++)
    {
        if (a[i]%2==0)
            k++;
        else k--;
        if (k == 0)
        {
            b[q] = abs(a[i]-a[i+1]);
            q++;
        }
    }
    for (int i=q; i>0; i--)
        for (int j=1; j<i; j++)
            if (b[j-1]>b[j])
            {
                k = b[j];
                b[j] = b[j-1];
                b[j-1] = k;
            }
    n=0; k=0;
    while (n<q&&k<=B)
    {
        k+=b[n];
        n++;
    }
    if (k>B)
        n--;
    cout << n;
    return 0;
}