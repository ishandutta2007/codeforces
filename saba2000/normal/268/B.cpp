#include <iostream>
#include <cmath>
using namespace std;
int main ()
{long long int n;
cin>>n;
cout << (n*n*(n+1)/2 - n*(n+1)*(2*n+1)/6 + n) << endl;
//system ("pause");
return 0;
}