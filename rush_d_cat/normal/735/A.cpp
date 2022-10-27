#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
char s[102];
int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", s+1);
    int from=0, to=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'G' || s[i] == 'T')
        {
            if(from == 0) from = i;
            else to = i;
        }
    }
    int pos = from;
    int ok = 0;
    //cout << from << " " << to << endl;
    while(pos <= to)
    {
        if(pos == to)
        {
            ok = 1;
            break;
        }
        if(s[pos] == '#')
        {
            ok = 0;
            break;
        }
        pos += k;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}