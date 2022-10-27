#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        if(i%4==1||i%4==2) printf("a");
        else printf("b");
    }
}