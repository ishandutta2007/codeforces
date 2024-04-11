#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector <int> a(n+1),b(m+1);
    for (int i=0;i<n+1;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<m+1;i++)
    {
        cin >> b[i];
    }
    if (n>m)
    {
        if (a[0]*b[0]<0) cout <<"-";
        cout << "Infinity";
    }
    else
    {
        if (n<m)
        {
            cout << "0/1";
        }
        else
        {
            int g=gcd(abs(a[0]),abs(b[0]));
            int a1=a[0]/g;
            int b1=b[0]/g;
            if (b1<0)
            {
                a1=-a1;
                b1=-b1;
            }
            cout << a1 << "/" << b1;
        }
    }
    return 0;
}