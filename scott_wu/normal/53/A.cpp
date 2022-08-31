#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string diction[100];
    for (int a = 0; a < n; a++)
        cin >> diction[a];
    string min;
    bool check = false;
    for (int a = 0; a < n; a++)
    {
        if (!check)
        {
           bool works = true;
           for (int b = 0; b < s.length(); b++)
               if (s[b] != diction[a][b])
                  works = false;
           if (works)
           {
              check = true;
              min = diction[a];
           }
        }
        else
        {
            bool works = true;
            for (int b = 0; b < s.length(); b++)
                if (s[b] != diction[a][b])
                   works = false;
            if (works && diction[a] < min)
            {
               check = true;
               min = diction[a];
            }
        }
    }
    if (check)
       cout << min;
    else
        cout << s;
}