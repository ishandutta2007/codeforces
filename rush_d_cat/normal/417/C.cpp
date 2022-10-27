#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
int main()
{
    cin >> n >> k;
    if(2*k>n-1)
    {
        cout << -1 << endl;
        return 0;
    }
    printf("%d\n", n*k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++) 
        {
            int tmp = ((i+j)>n)?(i+j-n):(i+j);
            printf("%d %d\n", i, tmp);
        }
    } 
}