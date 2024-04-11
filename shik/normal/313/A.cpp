// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    string s;
    cin>>s;
    int a=atoi(s.c_str());
    int b=atoi(s.substr(0, s.size() - 1).c_str());
    int c=atoi((s.substr(0, s.size() - 2) + s.back()).c_str());
    printf("%d\n",max(a,max(b,c)));
    return 0;
}