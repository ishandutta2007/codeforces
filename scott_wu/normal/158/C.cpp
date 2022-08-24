#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string loc;

void add (string x)
{
    loc = loc + "/" + x;
}

void prev ()
{
    //if (loc == "/") return;
    for (int i = loc.length() - 1; i >= 0; i--)
        if (loc[i] == '/')
        {
            loc = loc.substr (0, i);
            return;
        }
}

void update (string info)
{
    if (info[0] == '/')
    {
        loc = "";
        info = info.substr (1, info.length() - 1);
    }
    int last = 0;
    for (int i = 0; i < info.length(); i++)
    {
        if (info[i] == '/')
        {
            if (info[i-1] == '.')
                prev ();
            else
                add (info.substr (last, i - last));
            last = i + 1;
        }
    }
}

void print ()
{
    cout << loc;
    /*if (loc != "/")
        cout << "/";*/
    cout << "/\n";
}

int main()
{
    loc = "";
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "pwd") print();
        else
        {
            cin >> str;
            update (str + "/");
        }
    }
    //system ("Pause");
    return 0;
}