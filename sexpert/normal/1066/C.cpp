#include<bits/stdc++.h>
using namespace std;

int main()
{
    int pos[200000];
    int q;
    cin >> q;
    bool empty = true;
    int l = 200000, r = 200000;
    while(q--)
    {
        char type;
        int id;
        cin >> type >> id;
        if(type == 'L')
        {
            if(empty)
            {
                pos[id] = l;
                empty = false;
            }
            else
            {
                l--;
                pos[id] = l;
            }
        }
        if(type == 'R')
        {
            if(empty)
            {
                pos[id] = r;
                empty = false;
            }
            else
            {
                r++;
                pos[id] = r;
            }
        }
        if(type == '?')
        {
            cout << min(pos[id] - l, r - pos[id]) << endl;
        }
    }
}