#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <set>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int NICO = 10005;
const int MAKI = 100005;
const int INF = 100007;
char s[NICO];
int main()
{
    scanf("%s", s+1);
    int len = strlen(s+1);
    int res = 0;
    int pre=0;
    int cur=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
        {
            cur = i;
            res = max(res,cur-pre);
            pre = cur;
        }
    }
    
    res = max(res, len+1-pre);
    if(res==0) res=len+1;
    cout << res << endl;
}