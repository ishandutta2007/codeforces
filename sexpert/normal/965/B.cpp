#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    int field[200][200];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        {
            if(s[j] == '.') field[i][j] = 0;
            else field[i][j] = 1;
        }
    }
    int m = 0, res = 0;
    pair<int, int> pos = make_pair(0, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //cout << field[i][j];
            res = 0;
            for(int l = max(i - k + 1, 0); l <= min(n - k, i); l++)
            {
                bool flag = true;
                for(int p = 0; p < k; p++)
                {
                    if(field[l + p][j] == 1) flag = false;   
                }
                if(flag) res++;
            }
            for(int l = max(j - k + 1, 0); l <= min(n - k, j); l++)
            {
                bool flag = true;
                for(int p = 0; p < k; p++)
                {
                    if(field[i][l + p] == 1) flag = false;   
                }
                if(flag) {/*cout<<i<<" "<<j<<" vert\n";*/res++;}
            }
            if (res > m)
            {
                m = res;
                pos = make_pair(i, j);
            }
        }
        //cout << endl;
    }
    cout << pos.first + 1 << " " << pos.second + 1 << endl;
}