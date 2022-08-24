#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string, string> mmap;

int main()
{
    mmap["purple"] = "Power";
    mmap["green"] = "Time";
    mmap["blue"] = "Space";
    mmap["orange"] = "Soul";
    mmap["red"] = "Reality";
    mmap["yellow"] = "Mind";
    
    int N; cin >> N;
    cout << 6 - N << "\n";
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        mmap[s] = "";
    }
    
    for (map<string, string>::iterator it = mmap.begin(); it != mmap.end(); it++)
    {
        if (it->second != "")
            cout << it->second << "\n";
    }
}