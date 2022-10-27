#include <iostream>
#include <cstring>
using namespace std;
char s[12];
bool chk(int l, int r)
{
    for (int i = l; i <= r; i ++)
    {
        //printf("%d %d\n", i, r+l-i);
        if (s[i] != s[r - i + l]) {
            //printf("::%c %c\n", s[i], s[r+l-i]);
            return 0;
        }
    }
    //printf("yes\n");
    return 1;
}
bool zero(int l, int r)
{
    for (int i = l; i <= r; i ++)
    {
        if (s[i] != '0')  return 0;
    }
    return 1;
}
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    
    //chk(1, 3); return 0;
    bool flag = 0;

    for (int i = n; i >= 1; i --)
    {
        //printf("%d %d %d\n", 1, i, chk(1, i));
        if (zero(i + 1, n) && chk(1, i)) flag = 1;
    }

    printf("%s\n", flag ? "YES": "NO");

}