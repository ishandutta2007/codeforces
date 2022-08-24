#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

struct point
{
       string name;
       int nstar;
       bool err;
};

int main()
{
    int n;
    cin >> n;
    string type, tfirst, tsecond;
    vector <point> list;
    for (int a = 0; a < n; a++)
    {
        cin >> type;
        if (type == "typeof")
        {
           cin >> tfirst;
           int add = 0;
           string word = "";
           for (int b = 0; b < tfirst.length(); b++)
           {
               if (tfirst[b] == '&')
                  add--;
               else if (tfirst[b] == '*')
                    add++;
               else
                   word += tfirst[b];
           }
           bool check = false;
           if (word == "void")
           {
                    check = true;
                    if (add < 0)
                       cout << "errtype\n";
                    else
                    {
                        cout << "void";
                        for (int b = 0; b < add; b++)
                            cout << "*";
                        cout << "\n";
                    }
           }
           for (int b = list.size() - 1; b >= 0 && !check; b--)
           {
               if (list[b].name == word)
               {
                  check = true;
                  if (list[b].err || list[b].nstar + add < 0)
                     cout << "errtype\n";
                  else
                  {
                      cout << "void";
                      for (int c = 0; c < list[b].nstar + add; c++)
                          cout << "*";
                      cout << "\n";
                  }
               }
           }
           if (!check)
              cout << "errtype\n";
        }
        else
        {
            cin >> tfirst >> tsecond;
            point temp;
            int add = 0;
            string word = "";
            for (int b = 0; b < tfirst.length(); b++)
            {
                if (tfirst[b] == '&')
                   add--;
                else if (tfirst[b] == '*')
                     add++;
                else
                    word += tfirst[b];
            }
            bool check = false;
            if (word == "void")
            {
               check = true;
               temp.name = tsecond;
               temp.nstar = add;
               if (temp.nstar < 0)
                  temp.err = true;
               else
                   temp.err = false;
            }
            for (int b = list.size() - 1; b >= 0 && !check; b--)
            {
                if (list[b].name == word)
                {
                   check = true;
                   temp.name = tsecond;
                   temp.nstar = add + list[b].nstar;
                   temp.err = list[b].err;
                   if (temp.nstar < 0)
                      temp.err = true;
                }
            }
            if (!check)
            {
               temp.name = tsecond;
               temp.nstar = add;
               temp.err = true;
            }
            list.push_back (temp);
        }
    }
    return 0;
}