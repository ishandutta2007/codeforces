#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    vector <char> s;
    int lcp;
    char c;
    for (int i=0;i<n;i++)
    {
        c=getchar();
        int j=0;
        while( c!='\n')
        {
            if (i==0)
            {
                s.push_back(c);
            }
            else
            {
                if (j<lcp){
                if (s[j]==c)
                {
                    j++;
                }
                else lcp=j;
                }
            }
            c=getchar();
        }
        if (i==0) lcp=(int)s.size();
    }
    cout << lcp;

    return 0;
}