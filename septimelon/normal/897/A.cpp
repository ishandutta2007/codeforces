#include <iostream>

using namespace std;

struct oper
{
    int l;
    int r;
    char c1;
    char c2;
};

int main()
{
    //string p;
    char s[101];
    oper op[100]; int n, m;
    cin >> n >> m; n++;
    for (int i=1; i<n; i++)
        cin >> s[i];
    //getline (cin, p);
    for (int i=0; i<m; i++)
    {
        cin >> op[i].l >> op[i].r >> op[i].c1 >> op[i].c2;
    }
    for (int i=0; i<m; i++)
        for (int j=op[i].l; j<=op[i].r; j++)
            if (s[j]==op[i].c1) s[j]=op[i].c2;
    //cout << p;
    for (int i=1; i<n; i++)
    cout << s[i];
    //cout << p;
    return 0;
}