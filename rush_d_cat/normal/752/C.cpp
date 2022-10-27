#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int NICO = 200002;
char s[NICO];
int b[NICO];
int ok[NICO];
int main()
{
    int len;cin >> len;
    scanf("%s", s+1);
    int sta = 0, res = 0;
    if(len == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i=1;i<=len;i++)
    {
        if(s[i] == 'U') b[i] = 1;
        if(s[i] == 'D') b[i] = 4;
        if(s[i] == 'L') b[i] = 2;
        if(s[i] == 'R') b[i] = 3;
        if(i==len) res++;
        if(ok[5 - b[i]])
        {
            ok[1] = ok[2] = ok[3] = ok[4] = 0;
            ok[b[i]] = 1;
            ok[5-b[i]]=0; 
            res++;
        }
        ok[b[i]] = 1;
    }
    cout << res << endl;
}