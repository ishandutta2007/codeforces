#include <bits/stdc++.h>
using namespace std;

string query(int x, int y)
{
    cout << x << " " << y << "\n";
    cout.flush();
    string s;
    cin >> s;
    return s;
}

int main()
{
    int n;
    cin >> n;
    string firstColor = query(0, 0);
    int diff = 1 << (n - 2);
    int prevPoint = 0;
    int chosen = 1;
    int curLine = 1;
    int nextPoint = diff;
    while(true)
    {
        if(chosen == n)
            break;
        nextPoint = prevPoint + diff;
        string color = query(nextPoint, nextPoint);
        chosen++;
        if(color != firstColor)
            break;
        diff >>= 1;
        prevPoint = nextPoint;
        curLine = 2*prevPoint + 1;
    }

    int maxFirst, minOther;

    if(chosen < n)
    {
        maxFirst = prevPoint, minOther = nextPoint;
        curLine = 2*minOther - 1;
    }

    while(true)
    {
        if(chosen == n)
            break;
        int next = (maxFirst + minOther)/2;
        string color = query(next, next);
        if(color == firstColor)
            maxFirst = next;
        else
            minOther = next;
        chosen++;
        curLine = 2*minOther - 1;
    }
    if(curLine < 500)
        cout << 0 << " " << curLine << " " << curLine << " " << 0;
    else
    {
        int n = curLine/2, m = (curLine + 1)/2;
        cout << n - 1 << " " << m + 1 << " " << n + 1 << " " << m - 1 << endl;
    }
}