# include <algorithm>
# include <iostream>
using namespace std;
string s[]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int main ()
{
    int n;
    cin>>n;
    int x=5;
    int k=1;
    while(n>x)
    {
        n-=x;
        x*=2;
        k*=2;
    }
    int p=0;
    while(n>k)n-=k,p++;
    cout<<s[p]<<endl;
}