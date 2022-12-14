#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
string s;
int main()
{
    int n,n1;
    cin>>n;
    cin>>s;
    int p=0;
    for(int i=0;i<n;i++)
        if(s[i]=='0')
            p++;
        else
            p--;
    cout<<abs(p);
}