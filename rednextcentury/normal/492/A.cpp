# include<iostream>
# include<set>
#include <ios>
# include <algorithm>
using namespace std;
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int i=1;
    int num=0;
    int k=1;
    while(true)
    {
        num+=i;
        i+=k+1;
        if (num>n)
        {
            cout<<k-1<<endl;
            break;
        }
        k++;
    }
}