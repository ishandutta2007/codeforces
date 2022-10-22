#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string p, h;
        cin >> p >> h;
        sort(p.begin(), p.end());
        bool f = false;
        for(int i = 0; i <= (int)(h.size() - p.size()); i++){
            string s = h.substr(i, (int)p.size());
            sort(s.begin(), s.end());
            if(p == s){
                cout << "YES" << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << "NO" << endl;
    }
}