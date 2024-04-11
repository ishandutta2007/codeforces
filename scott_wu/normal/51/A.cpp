#include <iostream>
#include <vector>

using namespace std;

struct square
{
       char a, b, c, d;
};

square domino[1000];
vector <square> pile;

bool match (square x, square y)
{
     if (x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d)
        return true;
     if (x.a == y.b && x.b == y.c && x.c == y.d && x.d == y.a)
        return true;
     if (x.a == y.c && x.b == y.d && x.c == y.a && x.d == y.b)
        return true;
     if (x.a == y.d && x.b == y.a && x.c == y.b && x.d == y.c)
        return true;
     return false;
}

int main()
{
    int n;
    cin >> n;
    cin >> domino[0].a >> domino[0].b >> domino[0].d >> domino[0].c;
    char temp;
    for (int i = 1; i < n; i++)
    {
        cin >> temp >> temp;
        cin >> domino[i].a >> domino[i].b >> domino[i].d >> domino[i].c;
    }
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < pile.size(); j++)
            if (match (domino[i], pile[j]))
               check = false;
        if (check)
           pile.push_back (domino[i]);
    }
    cout << pile.size();
    return 0;
}