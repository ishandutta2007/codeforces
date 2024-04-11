#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
long long b,c,d,e;
string a;
int main()
{
    cin>>c;
    for (b=1; b<=c; b++)
    {
        cin>>a;
        if (a.length()>10) cout<<a[0]<<a.length()-2<<a[a.length()-1]<<endl; else cout<<a<<endl;
    }
}