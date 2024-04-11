#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

bool f[20][10];
int f7[20][10], f4[20][10], pr[20][10];
string s;
int a[20];

string rev(string s)
{
    string t;
    for (int i = 0; i < (int)s.length(); i++)
        t = s[i] + t;
    return t;
}

int main()
{
    int tt;
    cin >> tt;
    
    while (tt --)
    {
        cin >> s;
        s = rev(s);
        while ((int)s.length() < 19)
            s = s + "0";
        
        memset(a, 0, sizeof a);
        
        for (int i = 0; i < 19; i ++)
            a[i] = s[i] - '0';
        
        memset(f, 0, sizeof f);
        memset(f4, 0, sizeof f4);
        memset(f7, 0, sizeof f7);
        
        f[0][0] = 1;
        for (int i = 0; i < 19; i ++)
            for (int j = 0; j < 10; j ++)
                if (f[i][j])
                {
                    for (int k4 = 0; k4 <= 6; k4 ++)
                        for (int k7 = 0; k7 <= 6-k4; k7 ++)
                            if ((k4*4+k7*7+j)%10==a[i])
                            {
                                int y1 = ((k4*4+k7*7+j)-a[i])/10; 
                                f[i+1][y1] = 1;
                                f4[i+1][y1] = k4, 
                                f7[i+1][y1] = k7;
                                pr[i+1][y1] = j;
                            }
                }
        if(!f[19][0])
            puts("-1");
        else 
        {
            string a[6];
            for (int i = 0; i < 6; i ++) a[i] = "";
            for (int i = 19, j = 0; i >= 1; i --)
            {
                int k4 = f4[i][j];
                int k7 = f7[i][j];
                for (int k = 0; k < k4; k ++)
                    a[k] += '4';
                for (int k = 0; k < k7; k ++)
                    a[k4 + k] += '7';
                for (int k = 0; k < 6-k4-k7; k ++)
                    a[k4 + k7 + k] += '0';
                j = pr[i][j];
            }
            /*
            for (int i = 0; i < 6; i ++)
                a[i] = rev(a[i]);
            */
            for (int i = 0; i < 6; i ++)
            {
                while ((int)a[i].length()>=2 && a[i][0] == '0')
                    a[i] = a[i].substr(1);
            }
            
            for (int i = 0; i < 6; i ++)
                cout << a[i] << (i == 5? '\n': ' ');
        }
    }
    
    return 0;
}