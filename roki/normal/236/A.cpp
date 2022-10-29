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
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
bool b[10000];
int main()
{
    string s;
    cin >> s;
    int n,k = 0;
    int l = s.size();
    for(int i = 0;i < l;++i)
    {
        if(b[s[i]] == 0)
            k++;
        b[s[i]] = 1;
    }
    if(!(k & 1))
        cout << "CHAT WITH HER!\n";
    else
        cout << "IGNORE HIM!\n";
    return 0;   
}