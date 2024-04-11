#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000+10;
typedef long long ll;
char s[MAXN], res[3][30],s_[MAXN];
int pos[MAXN];
int l, r;
int main()
{
    scanf("%s", s+1);
    int i, j;
    for(i=1;i<=13;i++) res[1][i]='#',res[2][i]='#';
    for(i = 1; i <= 27; i++)
    {
        if(pos[s[i]] == 0)
            pos[s[i]] = i;
        else
            l = pos[s[i]], r = i;
    }
    if(r - l == 1) cout << "Impossible" << endl;
    else{
        res[1][13 - (r-l-1)/2] = s[l];
        int tmp = l;
        int cnt=0;
        for(i = r+1;i<=27;i++) s_[++cnt]=s[i];
        for(i = 1;i<l;i++) s_[++cnt]=s[i];
        
        for(i = 13 - (r-l-1)/2 + 1; i<=13;i++) res[1][i] = s[++tmp];
        for(i = 13;;i--)
        {
            if(s[tmp+1] == s[l]) break;
            res[2][i] = s[++tmp];
        }
        tmp=0;
        while(i>=1)
        {
            if(tmp+1>cnt) break;
            res[2][i] = s_[++tmp];
            i--;
        }
        
        for(i = 1; i <= 13;i++)
        {
            if(tmp+1>cnt) break;
            res[1][i] = s_[++tmp];
            if(tmp==cnt) break;
        }
    
        for(i = 1; i <= 13;i++) cout<<res[1][i];
        cout << endl;
        for(i = 1; i <= 13; i++) cout<<res[2][i];
        cout << endl;
    }
}