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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i < n / 2;++i)
    {
        int a1 = i,a2 = i + n / 2;
        if(s[i] == 'R')
            swap(a1,a2);
        cout << a1 + 1 << ' ' << a2 + 1 << endl;
    }
    return 0;
}