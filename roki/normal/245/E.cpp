#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    char c;
    int num = 0,nmax = 0,nmin = 0;
    while(scanf("%c",&c) != EOF)
    {
        if(c == '-')
            num--;
        if(c == '+')
            num++;
        nmax = max(nmax,num);
        nmin = min(num,nmin);
    }
    cout << nmax - nmin << endl;
    return 0;
}