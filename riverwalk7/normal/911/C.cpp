#include <iostream>
#include <fstream>
using namespace std;
int k1, k2, k3;
bool test(int a, int b, int c)
{
    for(int i=max(a, max(b, c)); i<1000; i++)
    {
        if(a%k1!=i%k1&&b%k2!=i%k2&&c%k3!=i%k3)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>k1>>k2>>k3;
    for(int i=0; i<10; i++)
    {
        for(int j=i; j<10; j++)
        {
            for(int k=j; k<10; k++)
            {
                if(test(i, j, k))
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}