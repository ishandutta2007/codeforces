#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> gems;
    gems["red"] = "Reality";
    gems["purple"] = "Power";
    gems["green"] = "Time";
    gems["blue"] = "Space";
    gems["orange"] = "Soul";
    gems["yellow"] = "Mind";
    set<string> left;
    left.insert("red");
    left.insert("purple");
    left.insert("green");
    left.insert("blue");
    left.insert("orange");
    left.insert("yellow");
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
            string color;
            cin >> color;
            left.erase(color);
    }
    cout << 6 - n << endl;
    for(auto gem : left)
    {
             cout << gems[gem] << endl;
    }
}