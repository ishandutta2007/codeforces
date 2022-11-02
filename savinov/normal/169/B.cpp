#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{

    int n;
    char c;
    vector <char> str;
    vector <char> pr;
    c=getchar();
    while (c!='\n')
    {
        str.push_back(c);
        c=getchar();
    }
    c=getchar();
    while (c!='\n')
    {
        pr.push_back(c);
        c=getchar();
    }
    sort(pr.begin(),pr.end());
    reverse(pr.begin(),pr.end());

    n=(int)str.size();
    int op=0;
    for (int i=0;(i<n)&&(op<(int)(pr.size()));i++){
        if (str[i]<pr[op])
        {
            str[i]=pr[op];
            op++;
        }

    }
    for (int i=0;i<(int)str.size();i++) cout << str[i];



    return 0;

}