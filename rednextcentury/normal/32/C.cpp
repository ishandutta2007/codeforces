# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
int p[100];
int main()
{
    long long n,m,s;
    cin>>n>>m>>s;
    cout<< ((n-1)/s + 1)*((m-1)/s + 1)*((n-1)%s+1)*((m-1)%s+1)<<endl;
}