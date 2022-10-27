#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 1000 + 10;
char s[NICO],c[5],m[5];
int res[100000];
vector<int> vec;
int main()
{
    scanf("%s", s+1);
    c[0]='R';c[1]='B';c[2]='Y';c[3]='G';
    int n = strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='!') vec.push_back(i);
        for(int j=0;j<4;j++)
        {
            if(s[i]==c[j])
            {
                m[i%4]=c[j];
            }
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            if(vec[i]%4==j)
            {
                res[m[j]]++;
            }
        }
    }
    cout << res['R'] << " " << res['B'] << " " << res['Y'] << " " << res['G'] << endl;
}