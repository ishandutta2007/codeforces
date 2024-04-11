#include <iostream>
#include <algorithm>
using namespace std;

int a[10];

int main()
{
    int minx = 2147483647, n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        minx = min(a[i], minx);
    }
    cout<<((minx xor a[2])+2)<<endl;
    return 0;
}