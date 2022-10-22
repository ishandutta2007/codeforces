#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a= new int[n]; int *b= new int [n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];
    long int suma=0;
    long int k;
    for (int i=n-1; i>0; i--)
        if (b[i]>b[i-1])
        {
            k=b[i]; b[i]=b[i-1]; b[i-1]=k;
        }
    for (int i=n-1; i>0; i--)
        if (b[i]>b[i-1])
        {
            k=b[i]; b[i]=b[i-1]; b[i-1]=k;
        }
    k=b[0]+b[1];
    for (int i=0; i<n; i++)
    {
        suma+=a[i];
        if (suma>k)
            break;
    }
    suma-=k;
    if (suma<=0)
        cout << "YES";
    else cout << "NO";
    return 0;
}