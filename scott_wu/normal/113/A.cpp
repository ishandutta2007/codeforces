#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
const int MAXN = 100100;

vector <char> words[MAXN];

string e[6] = {"soil", "alail", "rte", "arte", "sitini", "setini"};

void no ()
{
    cout << "NO\n";
    //system ("Pause");
}

int wtype (int a)
{
    for (int i = 0; i < 6; i++)
    {
        bool check = true;
        for (int j = 0; j < e[i].length(); j++)
            if (e[i][j] != words[a][j])
                check = false;
        if (check) return i + 1;
    }
    return 0;
}

int main()
{
    char ch = ' '; int n = 0;
    while (true)
    {
        ch = getchar();
        if (ch == ' ')
            n++;
        if (ch == '\n')
            break;
        words[n].push_back (ch);
    }
    n++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < words[i].size() / 2; j++)
            swap (words[i][j], words[i][words[i].size() - 1 - j]);
    if (n == 1)
    {
        cout << ((wtype(0)) ? "YES\n" : "NO\n");
        //system ("Pause");
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (wtype(i) == 0)
        {
            no();
            return 0;
        }
    int gender = wtype(0) % 2;
    int loc = 0;
    for (int i = 0; i < n; i++)
    {
        if ((wtype(i) % 2) != gender)
        {
            no();
            return 0;
        }
        int b = (wtype(i) - 1) / 2;
        if (b < loc)
        {
            no();
            return 0;
        }
        if (b == 1 && loc == 1)
        {
            no();
            return 0;
        }
        if (b == 2 && loc == 0)
        {
            no();
            return 0;
        }
        loc = b;
    }
    if (loc >= 1)
    {
        cout << "YES\n";
        //system ("Pause");
        return 0;
    }
    no();
    return 0;
}