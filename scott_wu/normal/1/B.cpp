#include <iostream>
#include <string>
#include <map>

using namespace std;
const int MAXK = 1000100;

int N;
string str;

string conv[MAXK];
//map <string, int> cmap;

int find (string str)
{
    int lo = 1, hi = MAXK;
    
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (str.length() < conv[mid].length() || (str.length() == conv[mid].length() && str < conv[mid]))
            hi = mid - 1;
        else
            lo = mid;
    }
    
    return lo;
}

string find (int x)
{
    return conv[x];
}

int main()
{
    string cur = "A";
    for (int i = 1; i < MAXK; i++)
    {
        conv[i] = cur;
        //cmap[cur] = i;
        
        int cloc;
        for (cloc = cur.length() - 1; cloc >= 0; cloc--)
            if (cur[cloc] != 'Z')
                break;
        
        if (cloc == -1 && cur[0] == 'Z')
        {
            int x = cur.length();
            cur = "";
            for (int j = 0; j < x + 1; j++)
                cur += 'A';
            //cout << cur << "\n";
        }
        else
        {
            cur[cloc]++;
            for (int j = cloc + 1; j < cur.length(); j++)
                cur[j] = 'A';
        }
    }
    
    //for (int i = 0; i < 30; i++)
    //    cout << conv[i] << "\n";
    
    cin >> N;
    
    for (int test = 0; test < N; test++)
    {
    
    cin >> str;
    
    int xcount = 0;
    for (int i = 0; i < str.length() - 1; i++)
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i+1] >= '0' && str[i+1] <= '9')
            xcount++;
    
    if (xcount == 1)
    {
        string str2 = "";
        int num = 0;
        for (int i = 0; i < str.length(); i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                str2 += str[i];
            else
                num = 10 * num + (int) (str[i] - '0');
        
        cout << 'R' << num << 'C' << find (str2) << "\n";
    }
    else
    {
        int num = 0, num2 = 0;
        bool good = false;
        
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == 'C')
                good = true;
            else if (good)
                num2 = 10 * num2 + (int) (str[i] - '0');
            else
                num = 10 * num + (int) (str[i] - '0');
        }
        
        cout << find (num2) << num << "\n";
    }
    
    }
    //system ("Pause");
    return 0;
}