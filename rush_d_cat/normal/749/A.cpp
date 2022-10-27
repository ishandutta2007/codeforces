#include <iostream>
using namespace std;
int main()
{
    int n;cin >> n;
    if(n==2)
    {
        printf("1\n");
        printf("2");
        return 0;
    }
    if(n==3)
    {
        printf("1\n");
        printf("3");
        return 0;
    }
    printf("%d\n", n/2);
    while(n)
    {
        if(n==3) {printf("3");n-=3;}
        else {printf("2 ");n-=2;};
    }

}