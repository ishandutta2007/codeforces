#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 105
int n , a[N] , b[N];

int main()
{
    int i , j , x , y , sa = 0 , sb = 0;
    cin >> n;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i],&b[i]) , sa += a[i] , sb += b[i];
    if ((sa + sb) & 1)
        puts("-1");
    else if (sa % 2 == 0 && sb % 2 == 0)
        puts("0");
    else
    {
        for (i = 0 ; i < n ; ++ i)
            if ((a[i] & 1) ^ (b[i] & 1))
                break;
        puts(i < n ? "1" : "-1");
    }
    //cout << "Hello world!" << endl;
    return 0;
}