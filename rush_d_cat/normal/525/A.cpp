#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int d = (int)'A' - (int)'a';
char s[1000000 + 2];
int cnt[300];
int main()
{
    int n;
    cin>>n>>s;
    int len = strlen(s);
    int res = 0;
    for(int i = 0; i  < len; i++)
    {
        if(i%2 == 0) cnt[(int)s[i]] ++;
        else {
            if(cnt[(int)s[i] - d] > 0) cnt[(int)s[i] - d] --;
            else res ++;
        }
    }
    cout << res <<endl;
    return 0;
}