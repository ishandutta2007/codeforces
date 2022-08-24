#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int MAXN = 110;

int n, m, k;
int gloc[MAXN];
int rloc[MAXN];
int gc, rc;

int main()
{
    for (int i = 0; i < MAXN; i++)
        gloc[i] = rloc[i] = -1;
    cin >> n >> m >> k;
    if (m == 1)
    {
        cout << "Second\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        gc = 0, rc = 0;
        for (int j = 0; j < m; j++)
        {
            char ch; cin >> ch;
            if (ch == 'G')
            {
                gloc[i] = j;
                gc++;
            }
            if (ch == 'R')
            {
                rloc[i] = j;
                rc++;
            }
        }
        if (gc + rc == m)
            gloc[i] = rloc[i] = -1;
    }
    bool check = false, check2 = false;
    for (int i = 0; i < n; i++)
    {
        if (gloc[i] != -1 && rloc[i] == -1)
            check = true;
        if (gloc[i] == -1 && rloc[i] != -1)
            check2 = true;
    }
    if (check || check2)
    {
        if (check && check2)
            cout << "Draw\n";
        if (check && !check2)
            cout << "First\n";
        if (check2 && !check)
            cout << "Second\n";
        //system ("Pause");
        return 0;
    }
    vector <int> col;
    for (int i = 0; i < n; i++)
    {
        if (gloc[i] != rloc[i])
        {
            if (abs (gloc[i] - rloc[i]) - 1 != 0)
                col.push_back (abs (gloc[i] - rloc[i]) - 1);
        }
    }
    check = true;
    for (int i = 0; i < 8; i++)
    {
        int n1 = 0;
        for (int j = 0; j < col.size(); j++)
            if (col[j] & (1 << i))
                n1++;
        if (n1 % (k + 1) != 0)
            check = false;
    }
    if (check)
        cout << "Second\n";
    else
        cout << "First\n";
    //system ("Pause");
    return 0;
}