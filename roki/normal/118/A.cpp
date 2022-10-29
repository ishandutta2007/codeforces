#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
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

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

bool bad(char c)
{
    string b = "aoyeui";
    forn (i, b.size())
        if(b[i] == c)
            return true;
    return false;
}

int main()
{
    char c;
    while(scanf("%c", &c) != EOF)
    {
        if(c >= 'A' && c <= 'Z')
            c -= 'A' - 'a';
        if(!bad(c) && c >= 'a' && c <= 'z')
            cout << '.' << c;
    }
    return 0;
}