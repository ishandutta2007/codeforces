#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <string> rat, wc, man;
    string r = "rat", w = "woman", c = "child", m = "man", cap = "captain";
    string captain, temp, temp2;
    for (int a = 0; a < n; a++)
    {
        cin >> temp >> temp2;
        if (temp2 == r)
           rat.push_back (temp);
        if (temp2 == w || temp2 == c)
           wc.push_back (temp);
        if (temp2 == m)
           man.push_back (temp);
        if (temp2 == cap)
           captain = temp;
    }
    for (int a = 0; a < rat.size(); a++)
        cout << rat[a] << "\n";
    for (int a = 0; a < wc.size(); a++)
        cout << wc[a] << "\n";
    for (int a = 0; a < man.size(); a++)
        cout << man[a] << "\n";
    cout << captain << "\n";
    return 0;
}