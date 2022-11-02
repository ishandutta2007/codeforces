#include <iostream>

using namespace std;

int main()
{
    int d,n;
    cin >> d >> n;
    int sum=0;int t=0;
    for (int i=0;i<n-1;i++)
    {
        int temp;
        cin >> temp;
        sum+=d-temp;
    }
    cout << sum<< endl;
    return 0;
}