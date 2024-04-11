#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
long long a[1000000];
int main()
{
    string s;
    cin>>s;
    long long n=s.length();
    long long AE=0,BE=0,AO=0,BO=0;
    long long odd=0;
    long long even=0;
    for (long long i=0;i<n;i++)
    {
        if (s[i]=='a')
        {
            if (i%2==0)
            {
                AE++;
                even+=AO;
                odd+=AE;
            }
            else
            {
                AO++;
                even+=AE;
                odd+=AO;
            }
        }
        else
        {
            if (i%2==0)
            {
                BE++;
                even+=BO;
                odd+=BE;
            }
            else
            {
                BO++;
                even+=BE;
                odd+=BO;
            }
        }
    }
    cout<<even<<" "<<odd<<endl;
}