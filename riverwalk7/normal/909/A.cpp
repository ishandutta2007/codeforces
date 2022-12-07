#include <iostream>
#include <string>
#include <algorithm>s
using namespace std;
string a, b;
int c;
string m[100000];
int main()
{
    cin>>a>>b;
    for(int i=1; i<=a.length(); i++)
    {
        for(int j=1; j<=a.length(); j++)
        {
            m[c] = a.substr(0, i)+b.substr(0, j);
            ++c;
        }
    }
    sort(m, m+c);
    cout<<m[0]<<endl;
}