#include <iostream>
# include <string>
using namespace std;
#define MOD 1000000007
long long p7[500000];
long long p3[500000];
int main()
{
    int n;
    cin>>n;
    p3[0]=p7[0]=1;
    for (int i=1;i<=3*n;i++)
    {
        p3[i]=(p3[i-1]*3)%MOD;
        p7[i]=(p7[i-1]*7)%MOD;
    }
    cout<<(p3[3*n]-p7[n]+MOD)%MOD<<endl;
}