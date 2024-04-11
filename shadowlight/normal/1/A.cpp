#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
long long a,b,c,d,e;
int main()
{
    cin>>a>>b>>c;
    d=a/c;
    if (a%c!=0) d++;
    e=b/c;
    if (b%c!=0) e++;
    cout<<d*e;
}