#include <iostream>
#include <string>

using namespace std;

string state;
int n;
int m, k;
bool direc, check = false;

void movec ()
{
    if (k == 1)
    {
        k = 2;
        direc = false;
    }
    else if (k == n)
    {
        k = n - 1;
        direc = true;
    }
    else if (direc)
        k--;
    else
        k++;
    if (k == 1)
        direc = false;
    if (k == n)
        direc = true;
    if (k == m)
        check = true;
}

void moves (int curt)
{
    if (state[curt] == '0')
    {
        if (m > k)
            m = min (n, m + 1);
        else if (m < k)
            m = max (1, m - 1);
    }
    else
    {
        if (direc)
            m = n;
        else
            m = 1;
    }
}

int main()
{
    cin >> n >> m >> k;
    string temp;
    cin >> temp >> temp;
    direc = (temp == "head"); //true if going toward 1
    cin >> state;
    for (int a = 0; a < state.length(); a++)
    {
        moves(a);
        movec();
        if (check)
        {
            cout << "Controller " << a + 1 << "\n";
            return 0;
        }
    }
    cout << "Stowaway\n";
    return 0;
}