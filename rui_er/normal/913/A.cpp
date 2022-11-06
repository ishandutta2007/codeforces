#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    cout<<m%int(pow(2, n))<<endl;
    return 0;
}