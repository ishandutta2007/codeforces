#include <cstdio>

using namespace std;

int a[3], b[3];

bool check()
{
    for(int i = 0; i < 3; ++ i)
        if(a[i] == b[i])
            return true;
    return false;
}

int main()
{
    for(int i = 0; i < 3; ++ i)
        scanf("%d", a + i);
    for(int i = 0; i < 3; ++ i)
        scanf("%d", b + i);
    printf(check()? "YES\n": "NO\n");
    return 0;
}