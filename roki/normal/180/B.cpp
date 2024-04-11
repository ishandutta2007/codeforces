#pragma comment(linker, "/STACK:167177216")

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
#include<iomanip>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int t2(int a, int b)
{
    int k = 1;
    forn (i, 100)
    {
        k *= a;
        if(k % b == 0)
            return i + 1;
        k %= b;
    }
    return 0;
}

bool t3(int a, int b)
{
    if((a % b) == 1)
        return true;
    return false;
}

bool t11(int a, int b)
{
    if(a % b == 1 && a * a % b == b - 1)
        return true;
    if(a % b == b - 1 && a * a % b == 1)
        return true;
    return false;
}

bool t6(int a, int b)
{
    int a2 = 0, a3 = 0, a11 = 0;
    for (int i = 2; i * i <= b; ++i)
    {
        if(b % i == 0)
        {
            int perm = 1;
            while(b % i == 0)
            {
                perm *= i;
                b /= i;
            }
            bool ok = false;
            if(t2(a, perm))
                ok = a2 = 1;
            if(t3(a, perm))
                ok = a3 = 1;
            if(t11(a, perm))
                ok = a11 = 1;
            if(!ok)
                return false;
        }
    }
    if(b > 1)
    {
        bool ok = false;
        int perm = b;
        if(t2(a, perm))
            ok = a2 = 1;
        if(t3(a, perm))
            ok = a3 = 1;
        if(t11(a, perm))
            ok = a11 = 1;
        if(!ok)
            return false;
    }
    return a2 + a3 + a11 >= 2;
}

int main()
{
    
    int a, b;
    cin >> a >> b;

    if(t2(a, b))
        cout << "2-type" << endl << t2(a, b) << endl;
    else
        if(t3(a, b))
            cout << "3-type" << endl;
        else
            if(t11(a, b))
                cout << "11-type" << endl;
            else
                if(t6(a, b))
                    cout << "6-type" << endl;
                else
                    cout << "7-type" << endl;

    return 0;
}