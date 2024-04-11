#include <iostream>

using namespace std;

int main()
{
    int a[6]; int sum=0;
    for (int i=0; i<6; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    bool t=false;
    for (int i=1; i<5; i++)
        for (int j=i+1; j<6; j++)
        if (2*(a[0]+a[i]+a[j])==sum)
            t=true;
    if (t==true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}